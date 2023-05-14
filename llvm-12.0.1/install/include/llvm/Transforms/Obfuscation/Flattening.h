#pragma once

#include "llvm/Passes/PassBuilder.h"
#include "llvm/Transforms/Utils.h"
#include "llvm/Transforms/Utils/LowerSwitch.h"

using namespace llvm;

namespace Pluto {

struct Flattening : PassInfoMixin<Flattening> {
    PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM);

    static bool isRequired() { return true; }
};

struct LegacyFlattening : public FunctionPass {
    static char ID;

    LegacyFlattening() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override;

    void getAnalysisUsage(AnalysisUsage &AU) const;
};

}; // namespace Pluto