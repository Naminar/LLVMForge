#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/InstrTypes.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
using namespace llvm;

namespace {
struct MyPass : public FunctionPass {
  static char ID;
  MyPass() : FunctionPass(ID) {}

  bool isFuncLogger(StringRef name) {
    return name == "dumpTrace";
  }

  virtual bool runOnFunction(Function &F) {
    if (isFuncLogger(F.getName())) {
      return false;
    }

    LLVMContext &Ctx = F.getContext();
    IRBuilder<> builder(Ctx);
    Type *retType = Type::getVoidTy(Ctx);

    ArrayRef<Type *> dumpTraceTypes = {
        builder.getInt8Ty()->getPointerTo()};

    FunctionType *dumpTraceFuncType =
        FunctionType::get(retType, dumpTraceTypes, false);

    FunctionCallee dumpTraceFunc =
        F.getParent()->getOrInsertFunction("dumpTrace", dumpTraceFuncType);

    for (auto &B : F) {
      for (auto &I : B) {

        if (dyn_cast<PHINode>(&I) == nullptr) {

            Value *valueAddr =
                ConstantInt::get(builder.getInt64Ty(), (int64_t)(&I));

            auto *ret = &I;
            builder.SetInsertPoint(ret);

            Value *arg = builder.CreateGlobalStringPtr(I.getOpcodeName());
            Value *args[] = {arg};

            builder.CreateCall(dumpTraceFunc, args);
        }
      }
    }
    return true;
  }
};
} // namespace

char MyPass::ID = 0;

// Automatically enable the pass.
// http://adriansampson.net/blog/clangpass.html
static void registerMyPass(const PassManagerBuilder &,
                                 legacy::PassManagerBase &PM) {
  PM.add(new MyPass());
}
static RegisterStandardPasses
    RegisterMyPass(PassManagerBuilder::EP_OptimizerLast, //EP_EarlyAsPossible,
                   registerMyPass);
