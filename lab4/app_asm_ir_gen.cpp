#include "../lab1/sim.h"

#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace llvm;

const int REG_FILE_SIZE = 20;
uint32_t REG_FILE[REG_FILE_SIZE];

std::string create_label(std::string myString) {
  outs() << "making label:" << myString << "\n";
  // outs() << myString.substr(0, myString.size()-1); 
  return myString.substr(0, myString.size()-1);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    outs() << "[ERROR] Need 1 argument: file with RISC-V assembler\n";
    return 1;
  }
  std::ifstream input;
  input.open(argv[1]);
  if (!input.is_open()) {
    outs() << "[ERROR] Can't open " << argv[1] << "\n";
    return 1;
  }

  LLVMContext context;
  // ; ModuleID = 'top'
  // source_filename = "top"
  Module *module = new Module("top", context);
  IRBuilder<> builder(context);
  Type *voidType = Type::getVoidTy(context);
  Type *int32Type = Type::getInt32Ty(context);

  //[32 x i32] regFile = {0, 0, 0, 0}
  ArrayType *regFileType = ArrayType::get(int32Type, REG_FILE_SIZE);
  module->getOrInsertGlobal("regFile", regFileType);
  GlobalVariable *regFile = module->getNamedGlobal("regFile");

  // declare void @main()
  FunctionType *funcType = FunctionType::get(builder.getVoidTy(), false);
  Function *mainFunc =
      Function::Create(funcType, Function::ExternalLinkage, "main", module);

  std::string name;
  std::string arg, arg1, arg2, arg3, arg4;
  std::unordered_map<std::string, BasicBlock *> BBMap;

  outs() << "\n#[FILE]:\nBBs:";

  while (input >> name) {
    // outs() << "comparing name:" << name << "\n";
    if (!name.compare("ctcall") || !name.compare("addCmpUgtContinues")) {
      input >> arg >> arg >> arg >> arg >> arg;
      continue;
    }
    if (!name.compare("sremAdd") || !name.compare("mullAddVal") || !name.compare("addCmpEqjumpIfNot")) {
      input >> arg >> arg >> arg >> arg;
      continue;
    }
    if (!name.compare("callSrem") || !name.compare("cmpSgt") || !name.compare("add")) {
      input >> arg >> arg >> arg;
      continue;
    }
    if (!name.compare("tcall") || !name.compare("jumpIfNot") || !name.compare("jumpIf")) {
      input >> arg >> arg;
      continue;
    }
    if (!name.compare("exit")) {
      continue;
    }

    outs() << " " << name;
    name = create_label(name);
    BBMap[name] = BasicBlock::Create(context, name, mainFunc);
  }
  outs() << "\n";
  input.close();
  input.open(argv[1]);

  // declare void @simPutPixel(i32 noundef, i32 noundef, i32 noundef)
  ArrayRef<Type *> simPutPixelParamTypes = {int32Type, int32Type, int32Type};
  FunctionType *simPutPixelType =
      FunctionType::get(voidType, simPutPixelParamTypes, false);
  FunctionCallee simPutPixelFunc =
      module->getOrInsertFunction("simPutPixel", simPutPixelType);

  // declare void @simFlush(...)
  FunctionType *simFlushType = FunctionType::get(voidType, false);
  FunctionCallee simFlushFunc =
      module->getOrInsertFunction("simFlush", simFlushType);

  FunctionType *SimRandType = FunctionType::get(Type::getInt32Ty(context), {voidType}, false);
  FunctionCallee SimRandFunc =
      module->getOrInsertFunction("simRand", SimRandType);

  while (input >> name) {
    if (!name.compare("exit")) {
      outs() << "\texit\n";
      builder.CreateRetVoid();
      if (input >> name) {
        outs() << "BB " << name << "\n";
        builder.SetInsertPoint(BBMap[create_label(name)]);//name.pop_back()
      }
      continue;
    }

    if (!name.compare("callSrem")) {
      input >> arg >> arg1 >> arg2;

      Value *const_val = ConstantInt::get(Type::getInt32Ty(context), std::stoi(arg1));
      Value *val1 = builder.CreateCall(SimRandFunc, {});
      Value *val2 = builder.CreateSRem(val1, const_val);

      Value *res_p = builder.CreateConstGEP2_32(regFileType, regFile, 0,
                                                std::stoi(arg2.substr(3)));
      builder.CreateStore(val2, res_p);
      continue;
    }

    if (!name.compare("tcall")) {
      input >> arg >> arg1;

      Value *val1 = builder.CreateCall(SimRandFunc, {});

      Value *res_p = builder.CreateConstGEP2_32(regFileType, regFile, 0,
                                                std::stoi(arg1.substr(3)));
      builder.CreateStore(val1, res_p);
      continue;
    }

    if (!name.compare("cmpSgt")) {
      input >> arg >> arg1 >> arg2;

      Value *val1 = builder.CreateLoad(
          int32Type, builder.CreateConstGEP2_32(regFileType, regFile, 0,
                                                std::stoi(arg.substr(3))));
      Value *const_val = ConstantInt::get(Type::getInt32Ty(context), std::stoi(arg1));
      Value *res_val = builder.CreateICmpSGT(val1, const_val);

      Value *res_p = builder.CreateConstGEP2_32(regFileType, regFile, 0,
                                                std::stoi(arg2.substr(3)));
      builder.CreateStore(res_val, res_p);
      continue;
    }

    if (!name.compare("jumpIfNot")) {
      input >> arg >> arg1 >> arg2;

      Value *reg_p = builder.CreateConstGEP2_32(regFileType, regFile, 0,
                                                std::stoi(arg.substr(3)));
      Value *reg_i1 = builder.CreateTrunc(builder.CreateLoad(int32Type, reg_p),
                                          builder.getInt1Ty());
      std::string label = create_label(arg2);//arg2.pop_back();
      builder.CreateCondBr(reg_i1, BBMap[label], BBMap[arg1]);
      builder.SetInsertPoint(BBMap[label]);
      continue;
    }

    if (!name.compare("sremAdd")) {
      input >> arg >> arg1 >> arg2 >> arg3;

      Value *const_val = ConstantInt::get(Type::getInt32Ty(context), std::stoi(arg1));
      Value *const_val1 = ConstantInt::get(Type::getInt32Ty(context), std::stoi(arg2));
      
      Value *val1 = builder.CreateLoad(
          int32Type, builder.CreateConstGEP2_32(regFileType, regFile, 0,
                                                std::stoi(arg.substr(3))));
      
      Value *val2 = builder.CreateSRem(val1, const_val);
      Value *res_val = builder.CreateAdd(val2, const_val1);

      Value *res_p = builder.CreateConstGEP2_32(regFileType, regFile, 0,
                                                std::stoi(arg3.substr(3)));
      builder.CreateStore(res_val, res_p);
      continue;
    }

    if (!name.compare("mullAddVal")) {
      input >> arg >> arg1 >> arg2 >> arg3;

      Value *val1 = builder.CreateLoad(
          int32Type, builder.CreateConstGEP2_32(regFileType, regFile, 0,
                                                std::stoi(arg.substr(3))));
      Value *val2 = builder.CreateLoad(
          int32Type, builder.CreateConstGEP2_32(regFileType, regFile, 0,
                                                std::stoi(arg1.substr(3))));
      Value *const_val = ConstantInt::get(Type::getInt32Ty(context), std::stoi(arg2));
      
      Value *res_p = builder.CreateConstGEP2_32(regFileType, regFile, 0,
                                                std::stoi(arg3.substr(3)));
      
      Value* res_val = builder.CreateAdd(builder.CreateMul(val1, val2), const_val);
      
      builder.CreateStore(res_val, res_p);
      continue;
    }

    if (!name.compare("ctcall")) {
      input >> arg >> arg1 >> arg2 >> arg3 >> arg4;
      
      Value *val1 = builder.CreateLoad(
          int32Type, builder.CreateConstGEP2_32(regFileType, regFile, 0,
                                                std::stoi(arg2.substr(3))));
      Value *val2 = builder.CreateLoad(
          int32Type, builder.CreateConstGEP2_32(regFileType, regFile, 0,
                                                std::stoi(arg3.substr(3))));
      Value *val3 = builder.CreateLoad(
          int32Type, builder.CreateConstGEP2_32(regFileType, regFile, 0,
                                                std::stoi(arg4.substr(3))));
      Value *args[] = {val1, val2, val3};
      builder.CreateCall(simPutPixelFunc, args);
      builder.CreateCall(simFlushFunc, {});
      continue;
    }

    if (!name.compare("addCmpUgtContinues")) {
      input >> arg >> arg1 >> arg2 >> arg3 >> arg4;

      Value *shared_reg = builder.CreateLoad(
          int32Type, builder.CreateConstGEP2_32(regFileType, regFile, 0,
                                                std::stoi(arg.substr(3))));
      Value *const_val = ConstantInt::get(Type::getInt32Ty(context), std::stoi(arg1));
      Value *const_val2 = ConstantInt::get(Type::getInt32Ty(context), std::stoi(arg2));

      builder.CreateStore(builder.CreateAdd(shared_reg, const_val),
                          builder.CreateConstGEP2_32(regFileType, regFile, 0,
                                                std::stoi(arg3.substr(3))));
      
      builder.CreateStore(builder.CreateICmpUGT(shared_reg, const_val2), 
                          builder.CreateConstGEP2_32(regFileType, regFile, 0,
                                                std::stoi(arg4.substr(3))));
      continue;
    }

    if (!name.compare("jumpIf")) {
      input >> arg >> arg1 >> arg2;

      Value *reg_p = builder.CreateConstGEP2_32(regFileType, regFile, 0,
                                                std::stoi(arg.substr(3)));
      Value *reg_i1 = builder.CreateTrunc(builder.CreateLoad(int32Type, reg_p),
                                          builder.getInt1Ty());
      std::string label = create_label(arg2);//arg2.pop_back();
      builder.CreateCondBr(reg_i1, BBMap[arg1], BBMap[label]);
      builder.SetInsertPoint(BBMap[label]);
      continue;
    }

    if (!name.compare("add")) {
      input >> arg >> arg1 >> arg2;
      
      Value *val1 = builder.CreateLoad(
          int32Type, builder.CreateConstGEP2_32(regFileType, regFile, 0,
                                                std::stoi(arg.substr(3))));
      Value *const_val = ConstantInt::get(Type::getInt32Ty(context), std::stoi(arg1));
      
      builder.CreateStore(builder.CreateAdd(val1, const_val), 
                          builder.CreateConstGEP2_32(regFileType, regFile, 0,
                                                std::stoi(arg2.substr(3))));
      continue;
    }

    if (!name.compare("addCmpEqjumpIfNot")) {
      input >> arg >> arg1 >> arg2 >> arg3 >> arg4;

      Value *val1 = builder.CreateLoad(
          int32Type, builder.CreateConstGEP2_32(regFileType, regFile, 0,
                                                std::stoi(arg.substr(3))));
      
      Value *add_const_val = ConstantInt::get(Type::getInt32Ty(context), std::stoi(arg1));
      Value *cmp_const_val = ConstantInt::get(Type::getInt32Ty(context), std::stoi(arg2));

      
      Value *val2 = builder.CreateICmpEQ(builder.CreateAdd(val1, add_const_val),
                            cmp_const_val);

      std::string label = create_label(arg4);//arg4.pop_back();
      builder.CreateCondBr(val2, BBMap[label], BBMap[arg3]);
      builder.SetInsertPoint(BBMap[label]);
      continue;
    }

    if (builder.GetInsertBlock()) {
      std::string label = create_label(name);//name.pop_back();
      builder.CreateBr(BBMap[label]);
      outs() << "\tbranch to " << name << "\n";
    }
    outs() << "BB " << name << "\n";
    std::string label = create_label(name);//name.pop_back();
    builder.SetInsertPoint(BBMap[label]);
  }

  outs() << "\n#[LLVM IR]:\n";
  module->print(outs(), nullptr);
  outs() << "\n";
  bool verif = verifyFunction(*mainFunc, &outs());
  outs() << "[VERIFICATION] " << (!verif ? "OK\n\n" : "FAIL\n\n");

  outs() << "\n#[Running code]\n";
  InitializeNativeTarget();
  InitializeNativeTargetAsmPrinter();

  ExecutionEngine *ee = EngineBuilder(std::unique_ptr<Module>(module)).create();
  ee->InstallLazyFunctionCreator([=](const std::string &fnName) -> void * {
    if (fnName == "simFlush") {
      return reinterpret_cast<void *>(simFlush);
    }
    if (fnName == "simPutPixel") {
      return reinterpret_cast<void *>(simPutPixel);
    }
    if (fnName == "simRand") {
      return reinterpret_cast<void *>(simRand);
    }
    return nullptr;
  });

  ee->addGlobalMapping(regFile, (void *)REG_FILE);
  ee->finalizeObject();

  simInit();

  ArrayRef<GenericValue> noargs;
  ee->runFunction(mainFunc, noargs);
  outs() << "#[Code was run]\n";

  simExit();
  return EXIT_SUCCESS;
}
