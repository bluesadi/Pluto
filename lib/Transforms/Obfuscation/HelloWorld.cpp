#include "llvm/Transforms/Obfuscation/HelloWorld.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"

using namespace llvm;

bool HelloWorld::runOnFunction(Function &F){
    if(enable){
        outs() << "Hello, " << F.getName() << "\n";
    }
    return false;
}

FunctionPass* llvm::createHelloWorldPass(bool enable){
    return new HelloWorld(enable);
}

char HelloWorld::ID = 0;