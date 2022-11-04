#include "llvm/IR/Function.h"
#include "llvm/Pass.h"

namespace llvm {

class HelloWorld : public FunctionPass {
public:
    static char ID;
    bool enable;

    HelloWorld(bool enable) : FunctionPass(ID) { this->enable = enable; }

    bool runOnFunction(Function &F);
};

FunctionPass *createHelloWorldPass(bool enable);

} // namespace llvm