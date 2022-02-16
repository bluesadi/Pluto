#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Transforms/Utils/Local.h"
#include "llvm/IR/Intrinsics.h"
#include "llvm/IR/IntrinsicsX86.h"
#include "llvm/Transforms/Obfuscation/Utils.h"
#include "llvm/Transforms/Obfuscation/RandomControlFlow.h"
#include <vector>
#include <cstdlib>
#include <ctime>
using std::vector;
using namespace llvm;

// 混淆次数，混淆次数越多混淆结果越复杂
static cl::opt<int> ObfuTimes("rcf-times", cl::init(1), cl::desc("Run RandomControlFlow pass <rcf-times> time(s)"));

bool RandomControlFlow::runOnFunction(Function &F){
    if(enable){
        INIT_CONTEXT(F);
        for(int i = 0;i < ObfuTimes;i ++){
            vector<BasicBlock*> origBB;
            for(BasicBlock &BB : F){
                origBB.push_back(&BB);
            }
            for(BasicBlock *BB : origBB){
                randcf(BB);
            }
        }
        return true;
    }
    return false;
}

void RandomControlFlow::insertRandomBranch(Value *randVar, BasicBlock *ifTrue, BasicBlock *ifFalse, BasicBlock *insertAfter){
    // 对随机数进行等价变换
    Value *alteredRandVar = alterVal(randVar, insertAfter);
    Value *randMod2 = BinaryOperator::Create(Instruction::And, alteredRandVar, CONST_I32(1), "", insertAfter);
    ICmpInst *condition = new ICmpInst(*insertAfter, ICmpInst::ICMP_EQ, randMod2, CONST_I32(1));
    BranchInst::Create(ifTrue, ifFalse, condition, insertAfter);
}

bool RandomControlFlow::randcf(BasicBlock *BB){
    // 拆分得到 entryBB, bodyBB, endBB
    // 其中所有的 PHI 指令都在 entryBB(如果有的话)
    // endBB 只包含一条终结指令
    BasicBlock *entryBB = BB;
    BasicBlock *bodyBB = entryBB->splitBasicBlock(BB->getFirstNonPHIOrDbgOrLifetime(), "bodyBB");
    BasicBlock *endBB = bodyBB->splitBasicBlock(bodyBB->getTerminator(), "endBB");
    BasicBlock *cloneBB = createCloneBasicBlock(bodyBB);
    
    // 在 entryBB 后插入随机跳转，使其能够随机跳转到第 bodyBB 或其克隆基本块 cloneBB
    entryBB->getTerminator()->eraseFromParent();
    // 老方案：通过rdrand指令生成随机数
    // Function *rdrand = Intrinsic::getDeclaration(entryBB->getModule(), Intrinsic::x86_rdrand_32);
    // CallInst *randVarStruct = CallInst::Create(rdrand->getFunctionType(), rdrand, "", entryBB);
    // // 通过 rdrand 内置函数获取随机数
    // Value *randVar = ExtractValueInst::Create(randVarStruct, 0, "", entryBB);

    // 方案一：通过分配一块栈空间实现类似于获取随机数的效果
    AllocaInst *randPtr = new AllocaInst(TYPE_I32, 0, "rand.ptr", entryBB);
    Value *randVar = new LoadInst(TYPE_I32, randPtr, "", entryBB);

    // 方案二：调用rand()函数获取随机数
    // Module &M = *BB->getModule();
    // Function *randFunc = cast<Function>(M.getOrInsertFunction("rand", FunctionType::getInt32Ty(*CONTEXT)).getCallee());
    // randFunc->setDSOLocal(true);
    // Value *randVar = CallInst::Create(randFunc->getFunctionType(), randFunc, "", entryBB);

    insertRandomBranch(randVar, bodyBB, cloneBB, entryBB);

    // 添加 bodyBB 到 bodyBB.clone 的虚假随机跳转
    bodyBB->getTerminator()->eraseFromParent();
    insertRandomBranch(randVar, endBB, cloneBB, bodyBB);
    // 添加 bodyBB.clone 到 bodyBB 的虚假随机跳转
    cloneBB->getTerminator()->eraseFromParent();
    insertRandomBranch(randVar, bodyBB, endBB, cloneBB);

    return true;
}

Value* RandomControlFlow::alterVal(Value *startVar,BasicBlock *insertAfter){
    uint32_t code = rand() % 3;
    Value *result;
    if(code == 0){
        //x = x * (x + 1) - x^2
        BinaryOperator *op1 = BinaryOperator::Create(Instruction::Add, startVar, CONST_I32(1), "", insertAfter);
        BinaryOperator *op2 = BinaryOperator::Create(Instruction::Mul, startVar, op1, "", insertAfter);
        BinaryOperator *op3 = BinaryOperator::Create(Instruction::Mul, startVar, startVar, "", insertAfter);
        BinaryOperator *op4 = BinaryOperator::Create(Instruction::Sub, op2, op3, "", insertAfter);
        result = op4;
    }else if(code == 1){
        //x = 3 * x * (x - 2) - 3 * x^2 + 7 * x
        BinaryOperator *op1 = BinaryOperator::Create(Instruction::Mul, startVar, CONST_I32(3), "", insertAfter);
        BinaryOperator *op2 = BinaryOperator::Create(Instruction::Sub, startVar, CONST_I32(2), "", insertAfter);
        BinaryOperator *op3 = BinaryOperator::Create(Instruction::Mul, op1, op2, "", insertAfter);
        BinaryOperator *op4 = BinaryOperator::Create(Instruction::Mul, startVar, startVar, "", insertAfter);
        BinaryOperator *op5 = BinaryOperator::Create(Instruction::Mul, op4, CONST_I32(3), "", insertAfter);
        BinaryOperator *op6 = BinaryOperator::Create(Instruction::Mul, startVar, CONST_I32(7), "", insertAfter);
        BinaryOperator *op7 = BinaryOperator::Create(Instruction::Sub, op3, op5, "", insertAfter);
        BinaryOperator *op8 = BinaryOperator::Create(Instruction::Add, op6, op7, "", insertAfter);
        result = op8;
    }else if(code == 2){
        //x = (x - 1) * (x + 3) - (x + 4) * (x - 3) - 9
        BinaryOperator *op1 = BinaryOperator::Create(Instruction::Sub, startVar, CONST_I32(1), "", insertAfter);
        BinaryOperator *op2 = BinaryOperator::Create(Instruction::Add, startVar, CONST_I32(3), "", insertAfter);
        BinaryOperator *op3 = BinaryOperator::Create(Instruction::Add, startVar, CONST_I32(4), "", insertAfter);
        BinaryOperator *op4 = BinaryOperator::Create(Instruction::Sub, startVar, CONST_I32(3), "", insertAfter);
        BinaryOperator *op5 = BinaryOperator::Create(Instruction::Mul, op1, op2, "", insertAfter);
        BinaryOperator *op6 = BinaryOperator::Create(Instruction::Mul, op3, op4, "", insertAfter);
        BinaryOperator *op7 = BinaryOperator::Create(Instruction::Sub, op5, op6, "", insertAfter);
        BinaryOperator *op8 = BinaryOperator::Create(Instruction::Sub, op7, CONST_I32(9), "", insertAfter);
        result = op8;
    }
    return result;
}

FunctionPass* llvm::createRandomControlFlow(bool enable){
    return new RandomControlFlow(enable);
}

char RandomControlFlow::ID = 0;