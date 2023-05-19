#pragma once

#include "llvm/Passes/PassBuilder.h"

using namespace llvm;

namespace Pluto {

struct HelloWorld : PassInfoMixin<HelloWorld> {
    PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM);

    static bool isRequired() { return true; }
};

struct LegacyHelloWorld : public FunctionPass {
    static char ID;

    LegacyHelloWorld() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override;
};

}; // namespace Pluto