#include "llvm/ADT/ArrayRef.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/Constant.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instruction.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/PassManager.h"
#include "llvm/IR/Type.h"
#include "llvm/Passes/OptimizationLevel.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"

using namespace llvm;

struct MyModPass : public PassInfoMixin<MyModPass> {
  bool isDumpTrace(StringRef name) {
    return name == "dumpTrace";
  }

  PreservedAnalyses run(Module &M, ModuleAnalysisManager &AM) {
    size_t is_app = M.getName().find("app");

    if(is_app!=std::string::npos) {
      // outs() << M.getName();
      for (auto &F : M) {
        if(isDumpTrace(F.getName())) {
          continue;
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
            } else { 
              // outs() << "PHY\n";
            }
          }
        }
      }
    }
    return PreservedAnalyses::all();
  };
};

PassPluginLibraryInfo getPassPluginInfo() {
  const auto callback = [](PassBuilder &PB) {
    // PB.registerPipelineStartEPCallback([&](ModulePassManager &MPM, auto) {
    //   MPM.addPass(MyModPass{});
    //   return true;
    // });
    PB.registerOptimizerLastEPCallback([&](ModulePassManager &MPM, auto) {
      MPM.addPass(MyModPass{});
      return true;
    });
  };

  return {LLVM_PLUGIN_API_VERSION, "MyPlugin", "0.0.1", callback};
};

/* When a plugin is loaded by the driver, it will call this entry point to
obtain information about this plugin and about how to register its passes.
*/
extern "C" LLVM_ATTRIBUTE_WEAK PassPluginLibraryInfo llvmGetPassPluginInfo() {
  return getPassPluginInfo();
}
