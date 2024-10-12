
#include "../lab1/sim.h"

#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
using namespace llvm;

int main() {
  LLVMContext context;
  // ; ModuleID = 'app.c'
  // source_filename = "app.c"
  Module *module = new Module("app.c", context);
  IRBuilder<> builder(context);

  // declare void @simPutPixel(i32 noundef, i32 noundef, i32 noundef)
  // local_unnamed_addr #1
  Type *voidType = Type::getVoidTy(context);
  ArrayRef<Type *> simPutPixelParamTypes = {Type::getInt32Ty(context),
                                            Type::getInt32Ty(context),
                                            Type::getInt32Ty(context)};
  FunctionType *simPutPixelType =
      FunctionType::get(voidType, simPutPixelParamTypes, false);
  FunctionCallee simPutPixelFunc =
      module->getOrInsertFunction("simPutPixel", simPutPixelType);

  // declare void @simFlush(...) local_unnamed_addr #1
  FunctionType *simFlushType = FunctionType::get(voidType, {voidType}, false);
  FunctionCallee simFlushFunc =
      module->getOrInsertFunction("simFlush", simFlushType);

  FunctionType *SimRandType = FunctionType::get(Type::getInt32Ty(context), {voidType}, false);
  FunctionCallee SimRandFunc = 
      module->getOrInsertFunction("simRand", SimRandType);

  // define dso_local void @app() local_unnamed_addr #0 {
  FunctionType *appFuncType = FunctionType::get(builder.getInt32Ty(), false);
  Function *appFunc =
      Function::Create(appFuncType, Function::ExternalLinkage, "app", module);

  // BasicBlocks:
  BasicBlock *BB0  = BasicBlock::Create(context, "", appFunc);
  BasicBlock *BB13 = BasicBlock::Create(context, "", appFunc);
  BasicBlock *BB16 = BasicBlock::Create(context, "", appFunc);
  BasicBlock *BB18 = BasicBlock::Create(context, "", appFunc);
  BasicBlock *BB24 = BasicBlock::Create(context, "", appFunc);
  BasicBlock *BB26 = BasicBlock::Create(context, "", appFunc);
  BasicBlock *BB32 = BasicBlock::Create(context, "", appFunc);
  BasicBlock *BB34 = BasicBlock::Create(context, "", appFunc);
  BasicBlock *BB36 = BasicBlock::Create(context, "", appFunc);
  BasicBlock *BB42 = BasicBlock::Create(context, "", appFunc);
  BasicBlock *BB43 = BasicBlock::Create(context, "", appFunc);


  builder.SetInsertPoint(BB0);
    Value *val1 = builder.CreateCall(SimRandFunc, {});

    Value *const1024 = ConstantInt::get(Type::getInt32Ty(context), 1024);
    Value *const4056 = ConstantInt::get(Type::getInt32Ty(context), 4056);
    Value *const512 = ConstantInt::get(Type::getInt32Ty(context), 512);
    Value *const0 = ConstantInt::get(Type::getInt32Ty(context), 0);

    Value *val2 = builder.CreateSRem(val1, const1024);
    Value *val3 = builder.CreateCall(SimRandFunc, {});
    Value *val4 = builder.CreateSRem(val3, const512);
    Value *val5 = builder.CreateCall(SimRandFunc, {});
    Value *val6 = builder.CreateCall(SimRandFunc, {});
    Value *val7 = builder.CreateSRem(val6, const1024);
    Value *val8 = builder.CreateCall(SimRandFunc, {});
    Value *val9 = builder.CreateSRem(val8, const4056);
    Value *val10 = builder.CreateCall(SimRandFunc, {});
    Value *val11 = builder.CreateSRem(val10, const4056);
    Value *val12 = builder.CreateICmpSGT(val2, const0);
    builder.CreateCondBr(val12, BB13, BB16);

  builder.SetInsertPoint(BB13);
    Value *val14 = builder.CreateSRem(val5, const1024);
    Value *val15 = builder.CreateNSWAdd(val14, builder.getInt32(16));
    // builder.CreateAdd(val14, builder.getInt32(1), "", true, true);
    builder.CreateBr(BB18);
  
  builder.SetInsertPoint(BB16);
    Value *val17 = builder.CreateNSWAdd(val7, builder.getInt32(16));
    builder.CreateBr(BB26);
  
  builder.SetInsertPoint(BB18);
    PHINode *val19 = builder.CreatePHI(builder.getInt32Ty(), 2);
    Value *val20 = builder.CreateNSWMul(val19, val15);
    Value *val21 = builder.CreateNSWAdd(val20, builder.getInt32(65535));
    builder.CreateCall(simPutPixelFunc, {val19, val4, val21});
    builder.CreateCall(simFlushFunc);
    Value *val22 = builder.CreateNSWAdd(val19, builder.getInt32(-1));
    Value *val23 = builder.CreateICmpUGT(val19, builder.getInt32(1));
    builder.CreateCondBr(val23, BB18, BB16);
  
  builder.SetInsertPoint(BB24);
    Value *val25 = builder.CreateNSWAdd(val9, builder.getInt32(16));
    builder.CreateBr(BB36);
  
  builder.SetInsertPoint(BB26);
    PHINode *val27 = builder.CreatePHI(builder.getInt32Ty(), 2);
    Value *val28 = builder.CreateNSWMul(val27, val17);
    Value *val29 = builder.CreateNSWAdd(val28, builder.getInt32(65535));
    builder.CreateCall(simPutPixelFunc, {val27, val4, val29});
    builder.CreateCall(simFlushFunc);
    Value *val30 = builder.CreateNSWAdd(val27, builder.getInt32(1));
    Value *val31 = builder.CreateICmpEQ(val30, builder.getInt32(1024));
    builder.CreateCondBr(val31, BB24, BB26);

  builder.SetInsertPoint(BB32);
    Value *val33 = builder.CreateICmpSGT(val4, builder.getInt32(0));
    builder.CreateCondBr(val33, BB34, BB42);
  
  builder.SetInsertPoint(BB34);
    Value *val35 = builder.CreateNSWAdd(val11, builder.getInt32(16));
    builder.CreateBr(BB43);
  
  builder.SetInsertPoint(BB36);
    PHINode *val37 = builder.CreatePHI(builder.getInt32Ty(), 2);
    Value *val38 = builder.CreateNSWMul(val37, val25);
    Value *val39 = builder.CreateNSWAdd(val38, builder.getInt32(65535));
    builder.CreateCall(simPutPixelFunc, {val2, val37, val39});
    builder.CreateCall(simFlushFunc);
    Value *val40 = builder.CreateNSWAdd(val37, builder.getInt32(1));
    Value *val41 = builder.CreateICmpEQ(val40, const512);
    builder.CreateCondBr(val41, BB32, BB36);
  
  builder.SetInsertPoint(BB42);
    builder.CreateRetVoid();
  
  builder.SetInsertPoint(BB43);
    PHINode *val44 = builder.CreatePHI(builder.getInt32Ty(), 2);
    Value *val45 = builder.CreateNSWMul(val44, val35);
    Value *val46 = builder.CreateNSWAdd(val45, builder.getInt32(65535));
    builder.CreateCall(simPutPixelFunc, {val2, val44, val46});
    builder.CreateCall(simFlushFunc);
    Value *val47 = builder.CreateNSWAdd(val44, builder.getInt32(-1));
    Value *val48 = builder.CreateICmpUGT(val44, builder.getInt32(1));
    builder.CreateCondBr(val48, BB43, BB42);

  val19->addIncoming(val2, BB13);
  val19->addIncoming(val22, BB18);

  val27->addIncoming(val2, BB16);
  val27->addIncoming(val30, BB26);

  val37->addIncoming(val4, BB24);
  val37->addIncoming(val40, BB36);

  val44->addIncoming(val4, BB34);
  val44->addIncoming(val47, BB43);

  module->print(outs(), nullptr);
  
  // LLVM IR Interpreter
  outs() << "[EE] Run\n";
  InitializeNativeTarget();
  InitializeNativeTargetAsmPrinter();

  ExecutionEngine *ee = EngineBuilder(std::unique_ptr<Module>(module)).create();
  ee->InstallLazyFunctionCreator([&](const std::string &fnName) -> void * {
    if (fnName == "simPutPixel") {
      return reinterpret_cast<void *>(simPutPixel);
    }
    if (fnName == "simFlush") {
      return reinterpret_cast<void *>(simFlush);
    }
    if (fnName == "simRand") {
      return reinterpret_cast<void *>(simRand);
    }
    return nullptr;
  });
  ee->finalizeObject();

  simInit();

  ArrayRef<GenericValue> noargs;
  GenericValue v = ee->runFunction(appFunc, noargs);
  outs() << "[EE] Result: " << v.IntVal << "\n";

  simExit();
  return EXIT_SUCCESS;
}
