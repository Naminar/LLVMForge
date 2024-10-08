#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
using namespace llvm;

struct MyModPass : public PassInfoMixin<MyModPass> {
  PreservedAnalyses run(Module &M, ModuleAnalysisManager &AM) {
    size_t found = M.getName().find("app");
    // outs() << "Dumping statistic for module " << M.getName() << "\n";
    if(found)
    for (auto &F : M) {
      for (auto &B : F) {
        for (auto &I : B) {
          for (auto &U : I.uses()) {
              Instruction *UseInst = cast<Instruction>(U.getUser());
              outs() << I.getOpcodeName() << " >> " << UseInst->getOpcodeName() << '\n';
          }
        }
      }
    }
    return PreservedAnalyses::all();
  };
};

PassPluginLibraryInfo getPassPluginInfo() {
  const auto callback = [](PassBuilder &PB) {
    PB.registerPipelineStartEPCallback([&](ModulePassManager &MPM, auto) {
      MPM.addPass(MyModPass{});
      return true;
    });
    // PB.registerOptimizerLastEPCallback([&](ModulePassManager &MPM, auto) {
    //   MPM.addPass(MyModPass{});
    //   return true;
    // });
  };

  return {LLVM_PLUGIN_API_VERSION, "MyPlugin", "0.0.1", callback};
};

/* When a plugin is loaded by the driver, it will call this entry point to
obtain information about this plugin and about how to register its passes.
*/
extern "C" LLVM_ATTRIBUTE_WEAK PassPluginLibraryInfo llvmGetPassPluginInfo() {
  return getPassPluginInfo();
}
