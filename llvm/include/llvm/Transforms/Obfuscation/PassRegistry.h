#include "llvm/IR/LegacyPassManager.h"

namespace llvm {

void registerModulePasses(legacy::PassManagerBase &MPM);

void registerFunctionPasses(legacy::PassManagerBase &MPM);

} // namespace llvm