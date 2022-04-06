#include "llvm/Transforms/Obfuscation/HelloWorld.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "Eigen/Dense"
#include <iostream>
using namespace Eigen;
using namespace llvm;

bool HelloWorld::runOnFunction(Function &F){
    if(enable){
        MatrixXd A(4, 5);
        Vector4d b;
        A << 0, 0, 0, 1, 1,
             0, 1, 1, 1, 1,
             1, 0, 1, 1, 1,
             1, 1, 1, 0, 1;
        b << 0, 0, 0, 0;
        VectorXd x = A.fullPivLu().kernel().col(0);
        std::cout << "DEBUG: " << x << "\n";
        outs() << "Hello, " << F.getName() << "\n";
    }
    return false;
}

FunctionPass* llvm::createHelloWorldPass(bool enable){
    return new HelloWorld(enable);
}

char HelloWorld::ID = 0;