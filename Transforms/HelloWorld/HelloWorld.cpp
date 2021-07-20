#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {

    class HelloWorld : public FunctionPass{
        public:
            static char ID;
            HelloWorld() : FunctionPass(ID) {}

            bool runOnFunction(Function &F){
                outs() << "Hello, " << F.getName() << "\n";
            }
    };
    
}

char HelloWorld::ID = 0;
static RegisterPass<HelloWorld> X("hello", "Say hello to each function.");