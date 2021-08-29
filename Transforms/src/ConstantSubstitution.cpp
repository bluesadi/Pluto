#include "llvm/IR/Function.h"
#include "llvm/IR/Module.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/CommandLine.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Utils.h"
using namespace llvm;
using std::vector;

#define MAX_RAND 32767
#define NUMBER_CONST_SUBST 2

// 混淆次数，混淆次数越多混淆结果越复杂
static cl::opt<int> obfuTimes("csub_loop", cl::init(1), cl::desc("Obfuscate a function <obfu_time> time(s)."));

namespace{

    class ConstantSubstitution : public FunctionPass {
        public:
            static char ID;

            ConstantSubstitution() : FunctionPass(ID) {
                srand(time(NULL));
            }

            bool runOnFunction(Function &F);

            // 对单个指令 BI 进行替换
            void substitute(BinaryOperator *BI);

            // 线性替换：val -> ax + by + c
            // 其中 val 为原常量 a, b 为随机常量 x, y 为随机全局变量 c = val - (ax + by)
            void linearSubstitute(BinaryOperator *BI, int i);

            // 按位运算替换：val -> (x << 5 | y >> 3) ^ c
            // 其中 val 为原常量x, y 为随机全局变量 c = val ^ (x << 5 | y >> 3)
            void bitwiseSubstitute(BinaryOperator *BI, int i);
    };
}

bool ConstantSubstitution::runOnFunction(Function &F){
    INIT_CONTEXT(F);
    for(int i = 0;i < obfuTimes;i ++){
        for(BasicBlock &BB : F){
            vector<Instruction*> origInst;
            for(Instruction &I : BB){
                origInst.push_back(&I);
            }
            for(Instruction *I : origInst){
                // 只对二元运算指令中的常量进行替换
                if(BinaryOperator *BI = dyn_cast<BinaryOperator>(I)){
                    // 仅对整数进行替换
                    if(BI->getType()->isIntegerTy(32)){
                        substitute(BI);
                    }
                }
            }
        }
    }
}

void ConstantSubstitution::linearSubstitute(BinaryOperator *BI, int i){
    Module &M = *BI->getModule();
    ConstantInt *val = cast<ConstantInt>(BI->getOperand(i));
    // 随机生成 x, y, a, b
    int randX = rand() % MAX_RAND, randY = rand() % MAX_RAND;
    int randA = rand() % MAX_RAND, randB = rand() % MAX_RAND;
    // 计算 c = val - (ax + by)
    APInt c = val->getValue() - (randA * randX + randB * randY);
    ConstantInt *constX = CONST(val->getType(), randX);
    ConstantInt *constY = CONST(val->getType(), randY);
    ConstantInt *constA = CONST(val->getType(), randA);
    ConstantInt *constB = CONST(val->getType(), randB);
    ConstantInt *constC = (ConstantInt*)CONST(val->getType(), c);
    // 创建全局变量 x, y
    GlobalVariable *x = new GlobalVariable(M, val->getType(), false, GlobalValue::PrivateLinkage, constX, "x");
    GlobalVariable *y = new GlobalVariable(M, val->getType(), false, GlobalValue::PrivateLinkage, constY, "y");
    LoadInst *opX = new LoadInst(val->getType(), x, "", BI);
    LoadInst *opY = new LoadInst(val->getType(), y, "", BI);
    // 构造 op = ax + by + c 表达式
    BinaryOperator *op1 = BinaryOperator::CreateMul(opX, constA, "", BI);
    BinaryOperator *op2 = BinaryOperator::CreateMul(opY, constB, "", BI);
    BinaryOperator *op3 = BinaryOperator::CreateAdd(op1, op2, "", BI);
    BinaryOperator *op4 = BinaryOperator::CreateAdd(op3, constC, "", BI);
    // 用表达式 ax + by + c 替换原常量操作数
    BI->setOperand(i, op4);
}

void ConstantSubstitution::bitwiseSubstitute(BinaryOperator *BI, int i){
    Module &M = *BI->getModule();
    ConstantInt *val = cast<ConstantInt>(BI->getOperand(i));
    // 随机生成 x, y
    unsigned randX = rand() % MAX_RAND, randY = rand() % MAX_RAND;
    // 计算 c = val ^ (x << 5 | y >> 3)
    APInt c = val->getValue() ^ (randX << 5 | randY >> 3);
    ConstantInt *constX = CONST(val->getType(), randX);
    ConstantInt *constY = CONST(val->getType(), randY);
    ConstantInt *const5 = CONST(val->getType(), 5);
    ConstantInt *const3 = CONST(val->getType(), 3);
    ConstantInt *constC = (ConstantInt*)CONST(val->getType(), c);
    // 创建全局变量 x, y
    GlobalVariable *x = new GlobalVariable(M, val->getType(), false, GlobalValue::PrivateLinkage, constX, "x");
    GlobalVariable *y = new GlobalVariable(M, val->getType(), false, GlobalValue::PrivateLinkage, constY, "y");
    LoadInst *opX = new LoadInst(val->getType(), x, "", BI);
    LoadInst *opY = new LoadInst(val->getType(), y, "", BI);
    // 构造 op = (x << 5 | y >> 3) ^ c 表达式
    BinaryOperator *op1 = BinaryOperator::CreateShl(opX, const5, "", BI);
    BinaryOperator *op2 = BinaryOperator::CreateLShr(opY, const3, "", BI);
    BinaryOperator *op3 = BinaryOperator::CreateOr(op1, op2, "", BI);
    BinaryOperator *op4 = BinaryOperator::CreateXor(op3, constC, "", BI);
    // 用表达式 (x << 5 | y >> 3) ^ c 替换原常量操作数
    BI->setOperand(i, op4);
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
static RegisterPass<ConstantSubstitution> X("csub", "Replace a constant value with equivalent instructions.");