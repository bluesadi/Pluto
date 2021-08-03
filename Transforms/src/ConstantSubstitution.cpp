#include "llvm/IR/Function.h"
#include "llvm/IR/Module.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/CommandLine.h"
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace llvm;
using std::vector;

#define MAX_RAND 32767
#define NUMBER_CONST_SUBST 2

// 可选的参数，指定一个基本块会被分裂成几个基本块，默认值为 2
static cl::opt<int> ObfuTime("obfu_time", cl::init(1), cl::desc("Obfuscate <obfu_time> time(s)."));

namespace{

    class ConstantSubstitution : public FunctionPass {
        public:
            static char ID;

            ConstantSubstitution() : FunctionPass(ID) {
                srand(time(NULL));
            }

            bool runOnFunction(Function &F);

            void substitute(BinaryOperator *BI);

            void linearSubstitute(BinaryOperator *BI, int i);

            void bitwiseSubstitute(BinaryOperator *BI, int i);
    };
}

bool ConstantSubstitution::runOnFunction(Function &F){
    for(int i = 0;i < ObfuTime;i ++){
        for(BasicBlock &BB : F){
            vector<Instruction*> origInst;
            for(Instruction &I : BB){
                origInst.push_back(&I);
            }
            for(Instruction *I : origInst){
                // 只对二元运算指令中的操作数进行替换
                if(isa<BinaryOperator>(I)){
                    BinaryOperator *BI = cast<BinaryOperator>(I);
                    substitute(BI);
                }
            }
        }
    }
}

// 线性替换：val -> ax + by + c
// 其中 val 为原常量 a, b 为随机常量 x, y 为随机全局变量 c = val - (ax + by)
void ConstantSubstitution::linearSubstitute(BinaryOperator *BI, int i){
    Module &M = *BI->getModule();
    ConstantInt *val = cast<ConstantInt>(BI->getOperand(i));
    // 随机生成 x, y, a, b
    int randX = rand() % MAX_RAND, randY = rand() % MAX_RAND;
    int randA = rand() % MAX_RAND, randB = rand() % MAX_RAND;
    // 计算 c = val - (ax + by)
    APInt c = val->getValue() - (randA * randX + randB * randY);
    ConstantInt *constX = ConstantInt::get(val->getType(), randX);
    ConstantInt *constY = ConstantInt::get(val->getType(), randY);
    ConstantInt *constA = ConstantInt::get(val->getType(), randA);
    ConstantInt *constB = ConstantInt::get(val->getType(), randB);
    ConstantInt *constC = (ConstantInt*)ConstantInt::get(val->getType(), c);
    // 创建全局变量 x, y
    GlobalVariable *x = new GlobalVariable(M, val->getType(), false, GlobalValue::PrivateLinkage, constX, "x");
    GlobalVariable *y = new GlobalVariable(M, val->getType(), false, GlobalVariable::PrivateLinkage, constY, "y");
    LoadInst *opX = new LoadInst(val->getType(), x, "", BI);
    LoadInst *opY = new LoadInst(val->getType(), y, "", BI);
    // 构造 op = ax + by + c 表达式
    BinaryOperator *op, *op1, *op2;
    op1 = BinaryOperator::CreateMul(opX, constA, "", BI);
    op2 = BinaryOperator::CreateMul(opY, constB, "", BI);
    op = BinaryOperator::CreateAdd(op1, op2, "", BI);
    op = BinaryOperator::CreateAdd(op, constC, "", BI);
    // 用表达式 ax + by + c 替换原常量操作数
    BI->setOperand(i, op);
}

// 按位运算替换：val -> (x << 5 | y >> 3) ^ c
// 其中 val 为原常量x, y 为随机全局变量 c = val ^ (x << 5 | y >> 3)
void ConstantSubstitution::bitwiseSubstitute(BinaryOperator *BI, int i){
    Module &M = *BI->getModule();
    ConstantInt *val = cast<ConstantInt>(BI->getOperand(i));
    // 随机生成 x, y
    int randX = rand() % MAX_RAND, randY = rand() % MAX_RAND;
    // 计算 c = val ^ (x << 5 | y >> 3)
    APInt c = val->getValue() ^ (randX << 5 | randY >> 3);
    ConstantInt *constX = ConstantInt::get(val->getType(), randX);
    ConstantInt *constY = ConstantInt::get(val->getType(), randY);
    ConstantInt *const5 = ConstantInt::get(val->getType(), 5);
    ConstantInt *const3 = ConstantInt::get(val->getType(), 3);
    ConstantInt *constC = (ConstantInt*)ConstantInt::get(val->getType(), c);
    // 创建全局变量 x, y
    GlobalVariable *x = new GlobalVariable(M, val->getType(), false, GlobalValue::PrivateLinkage, constX, "x");
    GlobalVariable *y = new GlobalVariable(M, val->getType(), false, GlobalVariable::PrivateLinkage, constY, "y");
    LoadInst *opX = new LoadInst(val->getType(), x, "", BI);
    LoadInst *opY = new LoadInst(val->getType(), y, "", BI);
    // 构造 op = (x << 5 | y >> 3) ^ c 表达式
    BinaryOperator *op, *op1, *op2;
    op1 = BinaryOperator::CreateShl(opX, const5, "", BI);
    op2 = BinaryOperator::CreateLShr(opY, const3, "", BI);
    op = BinaryOperator::CreateOr(op1, op2, "", BI);
    op = BinaryOperator::CreateXor(op, constC, "", BI);
    // 用表达式 (x << 5 | y >> 3) ^ c 替换原常量操作数
    BI->setOperand(i, op);
}

void ConstantSubstitution::substitute(BinaryOperator *BI){
    int operandNum = BI->getNumOperands();
    for(int i = 0;i < operandNum;i ++){
        if(isa<ConstantInt>(BI->getOperand(i))){
            int choice = rand() % NUMBER_CONST_SUBST;
            switch (choice) {
                case 0:
                    linearSubstitute(BI, i);
                    break;
                case 1:
                    bitwiseSubstitute(BI, i);
                    break;
                default:
                    break;
            }
        }
    }
}

char ConstantSubstitution::ID = 0;
static RegisterPass<ConstantSubstitution> X("sub", "Replace one binary instruction with equivalent instructions.");