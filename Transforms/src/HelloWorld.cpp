#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {

    class HelloWorld : public FunctionPass{
        public:
            static char ID;
            HelloWorld() : FunctionPass(ID) {}

            bool runOnFunction(Function &F);
    };
    
}

// runOnFunction 函数实现
bool HelloWorld::runOnFunction(Function &F){
	outs() << "Hello, " << F.getName() << "\n";
}

char HelloWorld::ID = 0;
// 注册该 HelloWorld Pass
static RegisterPass<HelloWorld> X("hlw", "My first line of LLVM Pass.");