#include "llvm/Transforms/Obfuscation/HelloWorld.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Transforms/Obfuscation/Utils.h"
#include <iostream>
using namespace llvm;

bool HelloWorld::runOnFunction(Function &F) {
  if (enable) {
    SKIP_IF_SHOULD(F);
    outs() << "Hello, " << F.getName() << ", " << readAnnotation(&F) << "\n";
  }
  return false;
}

FunctionPass *llvm::createHelloWorldPass(bool enable) {
  return new HelloWorld(enable);
}

char HelloWorld::ID = 0;