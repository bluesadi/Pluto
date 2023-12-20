#include "llvm/Support/CommandLine.h"
#include "llvm/IR/PassManager.h"
#include "llvm/Transforms/Obfuscation/HelloWorld.h"

using namespace llvm;
using namespace Pluto;

static cl::list<std::string> Passes("passes", cl::CommaSeparated, cl::Hidden,
                                    cl::desc("Obfuscation passes"));

ModulePassManager buildObfuscationPipeline() {
    ModulePassManager MPM;
    FunctionPassManager FPM;
    for (auto pass : Passes) {
        if (pass == "hlw") {
            FPM.addPass(HelloWorld());
        }
    }
    MPM.addPass(createModuleToFunctionPassAdaptor(std::move(FPM)));
    return MPM;
}
