#include "llvm/IR/PassManager.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Transforms/Obfuscation/Flattening.h"
#include "llvm/Transforms/Obfuscation/HelloWorld.h"
#include "llvm/Transforms/Utils/LowerSwitch.h"

using namespace llvm;
using namespace Pluto;

static cl::list<std::string> Passes("passes", cl::CommaSeparated, cl::Hidden, cl::desc("Obfuscation passes"));

struct LowerSwitchWrapper : LowerSwitchPass {
    static bool isRequired() { return true; }
};

ModulePassManager buildObfuscationPipeline() {
    ModulePassManager MPM;
    FunctionPassManager FPM;
    for (auto pass : Passes) {
        if (pass == "hlw") {
            FPM.addPass(HelloWorld());
        } else if (pass == "fla") {
            FPM.addPass(LowerSwitchWrapper());
            FPM.addPass(Flattening());
        }
    }
    MPM.addPass(createModuleToFunctionPassAdaptor(std::move(FPM)));
    return MPM;
}
