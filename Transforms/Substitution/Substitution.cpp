#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/CommandLine.h"
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace llvm;
using std::vector;

#define NUMBER_ADD_SUBST 4
#define NUMBER_SUB_SUBST 3
#define NUMBER_AND_SUBST 2
#define NUMBER_OR_SUBST 2
#define NUMBER_XOR_SUBST 2

// 可选的参数，指定一个基本块会被分裂成几个基本块，默认值为 2
static cl::opt<int> ObfuTime("obfu_time", cl::init(1), cl::desc("Obfuscate <obfu_time> time(s)."));

namespace{

    class Substitution : public FunctionPass {
        public:
            static char ID;
            Substitution() : FunctionPass(ID) {
                srand(time(NULL));
            }

            bool runOnFunction(Function &F);

            void substitute(BinaryOperator *BI);

            // 替换 Add 指令
            void substituteAdd(BinaryOperator *BI);
            void addNeg(BinaryOperator *BI);
            void addDoubleNeg(BinaryOperator *BI);
            void addRand(BinaryOperator *BI);
            void addRand2(BinaryOperator *BI);

            // 替换 Sub 指令
            void substituteSub(BinaryOperator *BI);
            void subNeg(BinaryOperator *BI);
            void subRand(BinaryOperator *BI);
            void subRand2(BinaryOperator *BI);
            // 替换 And 指令
            void substituteAnd(BinaryOperator *BI);
            void andSubstitute(BinaryOperator *BI);
            void andSubstituteRand(BinaryOperator *BI);
            
            // 替换 Or 指令
            void substituteOr(BinaryOperator *BI);
            void orSubstitute(BinaryOperator *BI);
            void orSubstituteRand(BinaryOperator *BI);

            // 替换 Xor 指令
            void substituteXor(BinaryOperator *BI);
            void xorSubstitute(BinaryOperator *BI);
            void xorSubstituteRand(BinaryOperator *BI);
    };
}

bool Substitution::runOnFunction(Function &F){
    for(int i = 0;i < ObfuTime;i ++){
        for(BasicBlock &BB : F){
            vector<Instruction*> origInst;
            for(Instruction &I : BB){
                origInst.push_back(&I);
            }
            for(Instruction *I : origInst){
                if(isa<BinaryOperator>(I)){
                    BinaryOperator *BI = cast<BinaryOperator>(I);
                    substitute(BI);
                }
            }
        }
    }
}

void Substitution::substitute(BinaryOperator *BI){
    bool flag = true;
    switch (BI->getOpcode()) {
        case BinaryOperator::Add:
            substituteAdd(BI);
            break;
        case BinaryOperator::Sub:
            substituteSub(BI);
            break;
        case BinaryOperator::And:
            substituteAnd(BI);
            break;
        case BinaryOperator::Or:
            substituteOr(BI);
            break;
        case BinaryOperator::Xor:
            substituteXor(BI);
            break;
        default:
            flag = false;
            break;
    }
    if(flag){
        BI->eraseFromParent();
    }
}


void Substitution::substituteAdd(BinaryOperator *BI){
    int choice = rand() % NUMBER_ADD_SUBST;
    switch (choice) {
        case 0:
            addNeg(BI);
            break;
        case 1:
            addDoubleNeg(BI);
            break;
        case 2:
            addRand(BI);
            break;
        case 3:
            addRand2(BI);
            break;
        default:
            break;
    }
}

// 加法替换：a = b + c -> a = b - (-c)
void Substitution::addNeg(BinaryOperator *BI){
    BinaryOperator *op;
    op = BinaryOperator::CreateNeg(BI->getOperand(1), "", BI);
    op = BinaryOperator::CreateSub(BI->getOperand(0), op, "", BI);
    BI->replaceAllUsesWith(op);
}

// 加法替换：a = b + c -> a = -(-b + (-c))
void Substitution::addDoubleNeg(BinaryOperator *BI){
    BinaryOperator *op, *op1, *op2;
    op1 = BinaryOperator::CreateNeg(BI->getOperand(0), "", BI);
    op2 = BinaryOperator::CreateNeg(BI->getOperand(1), "", BI);
    op = BinaryOperator::CreateAdd(op1, op2, "", BI);
    op = BinaryOperator::CreateNeg(op, "", BI);
    BI->replaceAllUsesWith(op);
}

// 加法替换：a = b + c -> r = rand (); a = b + r; a = a + c; a = a - r
void Substitution::addRand(BinaryOperator *BI){
    ConstantInt *r = (ConstantInt*)ConstantInt::get(BI->getType(), rand());
    BinaryOperator *op, *op1, *op2;
    op = BinaryOperator::CreateAdd(BI->getOperand(0), r, "", BI);
    op = BinaryOperator::CreateAdd(op, BI->getOperand(1), "", BI);
    op = BinaryOperator::CreateSub(op, r, "", BI);
    BI->replaceAllUsesWith(op);
}

// 加法替换：a = b + c -> r = rand (); a = b - r; a = a + b; a = a + r
void Substitution::addRand2(BinaryOperator *BI){
    ConstantInt *r = (ConstantInt*)ConstantInt::get(BI->getType(), rand());
    BinaryOperator *op, *op1, *op2;
    op = BinaryOperator::CreateSub(BI->getOperand(0), r, "", BI);
    op = BinaryOperator::CreateAdd(op, BI->getOperand(1), "", BI);
    op = BinaryOperator::CreateAdd(op, r, "", BI);
    BI->replaceAllUsesWith(op);
}

void Substitution::substituteSub(BinaryOperator *BI){
    int choice = rand() % NUMBER_SUB_SUBST;
    switch (choice) {
        case 0:
            subNeg(BI);
            break;
        case 1:
            subRand(BI);
            break;
        case 2:
            subRand2(BI);
            break;
        default:
            break;
    }
}

// 减法替换：a = b - c -> a = b + (-c)
void Substitution::subNeg(BinaryOperator *BI){
    BinaryOperator *op;
    op = BinaryOperator::CreateNeg(BI->getOperand(1), "", BI);
    op = BinaryOperator::CreateAdd(BI->getOperand(0), op, "", BI);
    BI->replaceAllUsesWith(op);
}

// 减法替换：a = b - c -> r = rand (); a = b + r; a = a - c; a = a - r
void Substitution::subRand(BinaryOperator *BI){
    ConstantInt *r = (ConstantInt*)ConstantInt::get(BI->getType(), rand());
    BinaryOperator *op, *op1, *op2;
    op = BinaryOperator::CreateAdd(BI->getOperand(0), r, "", BI);
    op = BinaryOperator::CreateSub(op, BI->getOperand(1), "", BI);
    op = BinaryOperator::CreateSub(op, r, "", BI);
    BI->replaceAllUsesWith(op);
}

// 减法替换：a = b - c -> a = b - r; a = a - c; a = a + r
void Substitution::subRand2(BinaryOperator *BI){
    ConstantInt *r = (ConstantInt*)ConstantInt::get(BI->getType(), rand());
    BinaryOperator *op, *op1, *op2;
    op = BinaryOperator::CreateSub(BI->getOperand(0), r, "", BI);
    op = BinaryOperator::CreateSub(op, BI->getOperand(1), "", BI);
    op = BinaryOperator::CreateAdd(op, r, "", BI);
    BI->replaceAllUsesWith(op);
}

void Substitution::substituteXor(BinaryOperator *BI){
    int choice = rand() % NUMBER_XOR_SUBST;
    switch (choice) {
        case 0:
            xorSubstitute(BI);
            break;
        case 1:
            xorSubstituteRand(BI);
            break;
        default:
            break;
    }
}

// 异或替换：a = b ^ c -> a = ~b & c | b & ~c
void Substitution::xorSubstitute(BinaryOperator *BI){
    BinaryOperator *op, *op1, *op2, *op3;
    op1 = BinaryOperator::CreateNot(BI->getOperand(0), "", BI);
    op1 = BinaryOperator::CreateAnd(op1, BI->getOperand(1), "", BI);
    op2 = BinaryOperator::CreateNot(BI->getOperand(1), "", BI);
    op2 = BinaryOperator::CreateAnd(BI->getOperand(0), op2, "", BI);
    op = BinaryOperator::CreateOr(op1, op2, "", BI);
    BI->replaceAllUsesWith(op);
}

// 异或替换：a = b ^ c -> (b ^ r) ^ (c ^ r) <=> (~b & r | b & ~r) ^ (~c & r | c & ~r)
void Substitution::xorSubstituteRand(BinaryOperator *BI){
    ConstantInt *r = (ConstantInt*)ConstantInt::get(BI->getType(), rand());
    BinaryOperator *op, *op1, *op2, *op3;
    op1 = BinaryOperator::CreateNot(BI->getOperand(0), "", BI);
    op1 = BinaryOperator::CreateAnd(op1, r, "", BI);
    op2 = BinaryOperator::CreateNot(r, "", BI);
    op2 = BinaryOperator::CreateAnd(BI->getOperand(0), op2, "", BI);
    op = BinaryOperator::CreateOr(op1, op2, "", BI);
    op1 = BinaryOperator::CreateNot(BI->getOperand(1), "", BI);
    op1 = BinaryOperator::CreateAnd(op1, r, "", BI);
    op2 = BinaryOperator::CreateNot(r, "", BI);
    op2 = BinaryOperator::CreateAnd(BI->getOperand(1), op2, "", BI);
    op3 = BinaryOperator::CreateOr(op1, op2, "", BI);
    op = BinaryOperator::CreateXor(op, op3, "", BI);
    BI->replaceAllUsesWith(op);
}

void Substitution::substituteAnd(BinaryOperator *BI){
    int choice = rand() % NUMBER_AND_SUBST;
    switch (choice) {
        case 0:
            andSubstitute(BI);
            break;
        case 1:
            andSubstituteRand(BI);
            break;
        default:
            break;
    }
}

// 与替换：a = b & c -> a = (b ^ ~c) & b
void Substitution::andSubstitute(BinaryOperator *BI){
    BinaryOperator *op;
    op = BinaryOperator::CreateNot(BI->getOperand(1), "", BI);
    op = BinaryOperator::CreateXor(BI->getOperand(0), op, "", BI);
    op = BinaryOperator::CreateAnd(op, BI->getOperand(0), "", BI);
    BI->replaceAllUsesWith(op);
}

// 与替换：a = b & c -> a = ~(~b | ~c) & (r | ~r)
void Substitution::andSubstituteRand(BinaryOperator *BI){
    ConstantInt *r = (ConstantInt*)ConstantInt::get(BI->getType(), rand());
    BinaryOperator *op, *op1;
    op = BinaryOperator::CreateNot(BI->getOperand(0), "", BI);
    op1 = BinaryOperator::CreateNot(BI->getOperand(1), "", BI);
    op = BinaryOperator::CreateOr(op, op1, "", BI);
    op = BinaryOperator::CreateNot(op, "", BI);
    op1 = BinaryOperator::CreateNot(r, "", BI);
    op1 = BinaryOperator::CreateOr(r, op1, "", BI);
    op = BinaryOperator::CreateAnd(op, op1, "", BI);
    BI->replaceAllUsesWith(op);
}

void Substitution::substituteOr(BinaryOperator *BI){
    int choice = rand() % NUMBER_OR_SUBST;
    switch (choice) {
        case 0:
            orSubstitute(BI);
            break;
        case 1:
            orSubstituteRand(BI);
            break;
        default:
            break;
    }
}

// 或替换：a = b | c -> a = (b & c) | (b ^ c)
void Substitution::orSubstitute(BinaryOperator *BI){
    BinaryOperator *op, *op1;
    op = BinaryOperator::CreateAnd(BI->getOperand(0), BI->getOperand(1), "", BI);
    op1 = BinaryOperator::CreateXor(BI->getOperand(0), BI->getOperand(1), "", BI);
    op = BinaryOperator::CreateOr(op, op1, "", BI);
    BI->replaceAllUsesWith(op);
}

// 或替换：a = b | c -> a = ~(~b & ~c) & (r | ~r)
void Substitution::orSubstituteRand(BinaryOperator *BI){
    ConstantInt *r = (ConstantInt*)ConstantInt::get(BI->getType(), rand());
    BinaryOperator *op, *op1;
    op = BinaryOperator::CreateNot(BI->getOperand(0), "", BI);
    op1 = BinaryOperator::CreateNot(BI->getOperand(1), "", BI);
    op = BinaryOperator::CreateAnd(op, op1, "", BI);
    op = BinaryOperator::CreateNot(op, "", BI);
    op1 = BinaryOperator::CreateNot(r, "", BI);
    op1 = BinaryOperator::CreateOr(r, op1, "", BI);
    op = BinaryOperator::CreateAnd(op, op1, "", BI);
    BI->replaceAllUsesWith(op);
}

char Substitution::ID = 0;
static RegisterPass<Substitution> X("sub", "Replace one binary instruction with equivalent instructions.");