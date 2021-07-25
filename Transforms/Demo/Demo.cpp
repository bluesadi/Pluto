#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {

    class HelloWorld : public FunctionPass{
        public:
            static char ID;
            HelloWorld() : FunctionPass(ID) {}

// 遍历函数 F 中的基本块 BB 的指令 I 的所有操作数 V
bool runOnFunction(Function &F){
    for(BasicBlock &BB : F){
        for(Instruction &I : BB){
            for(int i = 0;i < I.getNumOperands();i ++){
                Value *V = I.getOperand(i);
            }
        }
    }
}
    };
    
}

char HelloWorld::ID = 0;
static RegisterPass<HelloWorld> X("hello", "Say hello to each function.");