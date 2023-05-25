#pragma once

#include "llvm/Passes/PassBuilder.h"
#include "llvm/Transforms/Utils.h"

using namespace llvm;

namespace Pluto {

struct SymbolObfuscation : PassInfoMixin<SymbolObfuscation> {
    PreservedAnalyses run(Module &M, ModuleAnalysisManager &AM);

    static bool isRequired() { return true; }
};

}; // namespace Pluto