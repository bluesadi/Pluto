#include "llvm/Transforms/Obfuscation/HelloWorld.h"

#include "llvm/Analysis/AliasAnalysis.h"
#include "llvm/Transforms/Utils/LowerSwitch.h"

namespace Pluto {

PreservedAnalyses Pluto::HelloWorld::run(Function &F, FunctionAnalysisManager &AM) {
    outs() << "Hello, " << F.getName() << "\n";
    return PreservedAnalyses::all();
}

}; // namespace Pluto