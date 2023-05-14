#include "llvm/Transforms/Obfuscation/HelloWorld.h"
#include "llvm/Analysis/AliasAnalysis.h"
#include "llvm/Transforms/Utils/LowerSwitch.h"

namespace HelloWorld {
bool visit(Function &F) {
    outs() << "Hello, " << F.getName() << "\n";
    return false;
}
} // namespace HelloWorld

PreservedAnalyses Pluto::HelloWorld::run(Function &F, FunctionAnalysisManager &AM) {
    ::HelloWorld::visit(F);
    return PreservedAnalyses::all();
}

bool Pluto::LegacyHelloWorld::runOnFunction(Function &F) { return ::HelloWorld::visit(F); }
