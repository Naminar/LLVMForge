// #include "../sim.h"

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
    

  module->print(outs(), nullptr);
  // LLVM IR Interpreter
  // outs() << "[EE] Run\n";
  // InitializeNativeTarget();
  // InitializeNativeTargetAsmPrinter();

  // ExecutionEngine *ee = EngineBuilder(std::unique_ptr<Module>(module)).create();
  // ee->InstallLazyFunctionCreator([&](const std::string &fnName) -> void * {
  //   if (fnName == "simPutPixel") {
  //     return reinterpret_cast<void *>(simPutPixel);
  //   }
  //   if (fnName == "simFlush") {
  //     return reinterpret_cast<void *>(simFlush);
  //   }
  //   return nullptr;
  // });
  // ee->finalizeObject();

  // simInit();

  // ArrayRef<GenericValue> noargs;
  // GenericValue v = ee->runFunction(appFunc, noargs);
  // outs() << "[EE] Result: " << v.IntVal << "\n";

  // simExit();
  return EXIT_SUCCESS;
}
