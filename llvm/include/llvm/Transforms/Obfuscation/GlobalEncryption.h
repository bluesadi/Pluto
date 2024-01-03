#pragma once

#include "llvm/Passes/PassBuilder.h"

using namespace llvm;

namespace Pluto {

struct GlobalEncryption : PassInfoMixin<GlobalEncryption> {
    void insertArrayDecryption(Module &M, GlobalVariable *GV, uint64_t key, uint64_t eleNum);

    void insertIntDecryption(Module &M, GlobalVariable *GV, uint64_t key);

    PreservedAnalyses run(Module &M, ModuleAnalysisManager &AM);

    static bool isRequired() { return true; }
};

}; // namespace Pluto