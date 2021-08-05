#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Transforms/Utils/ValueMapper.h"
#include "llvm/Transforms/Utils/Cloning.h"
#include "llvm/Transforms/Utils/Local.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Intrinsics.h"
#include "llvm/IR/IntrinsicsX86.h"
#include "SplitBasicBlock.h"
#include <vector>
#include <cstdlib>
#include <ctime>
using std::vector;
using namespace llvm;
#define CONST(T,V) ConstantInt::get(T, V, false)

// 混淆次数，混淆次数越多混淆结果越复杂
static cl::opt<int> obfuTimes("rcf_loop", cl::init(1), cl::desc("Obfuscate a function <rcf_loop> time(s)."));

namespace{
    class RandomControlFlow : public FunctionPass{
        public:
            static char ID;

            RandomControlFlow() : FunctionPass(ID){
                srand(time(NULL));
            }

            BasicBlock* alterBB(BasicBlock *BB);

            // 创建克隆块
            BasicBlock* createAlteredBasicBlock(BasicBlock *BB);

            // 对变量 origVar 进行恒等变换
            // 并插入到基本块 insertAfter 之后
            Value* transformVar(Value *origVar,BasicBlock *insertAfter);

            // 添加随机跳转
            Value* insertRandomBranch(BasicBlock *BB, BasicBlock *IfTrue, BasicBlock *IfFalse);

            // 以基本块为单位进行混淆
            bool randcf(BasicBlock *BB);

            bool runOnFunction(Function &F);
    };
}

void fixStack(Function &F) {
    vector<Instruction*> origReg;
    BasicBlock &entryBB = F.getEntryBlock();
    for(BasicBlock &BB : F){
        for(Instruction &I : BB){
            if(!(isa<AllocaInst>(&I) && I.getParent() == &entryBB) 
                && I.isUsedOutsideOfBlock(&BB)){
                origReg.push_back(&I);
            }
        }
    }
    for(Instruction *I : origReg){
        DemoteRegToStack(*I, entryBB.getTerminator());
    }
}

bool RandomControlFlow::runOnFunction(Function &F){
    FunctionPass *pass = createSplitBasicBlockPass();
    pass->runOnFunction(F);
    for(int i = 0;i < obfuTimes;i ++){
        vector<BasicBlock*> origBB;
        for(BasicBlock &BB : F){
            origBB.push_back(&BB);
        }
        for(BasicBlock *BB : origBB){
            randcf(BB);
        }
        fixStack(F);
    }
    return true;
}

Value* RandomControlFlow::transformVar(Value *origVar,BasicBlock *insertAfter){
    IntegerType *i32 = Type::getInt32Ty(origVar->getContext());
    int code = rand() % 3;
    Value *result;
    if(code == 0){
        //x = x * (x + 1) - x^2
        BinaryOperator *op1 = BinaryOperator::Create(Instruction::Add, origVar, CONST(i32, 1), "", insertAfter);
        BinaryOperator *op2 = BinaryOperator::Create(Instruction::Mul, origVar, op1, "", insertAfter);
        BinaryOperator *op3 = BinaryOperator::Create(Instruction::Mul, origVar, origVar, "", insertAfter);
        BinaryOperator *op4 = BinaryOperator::Create(Instruction::Sub, op2, op3, "", insertAfter);
        result = op4;
    }else if(code == 1){
        //x = 3 * x * (x - 2) - 3 * x^2 + 7 * x
        BinaryOperator *op1 = BinaryOperator::Create(Instruction::Mul, origVar, CONST(i32, 3), "", insertAfter);
        BinaryOperator *op2 = BinaryOperator::Create(Instruction::Sub, origVar, CONST(i32, 2), "", insertAfter);
        BinaryOperator *op3 = BinaryOperator::Create(Instruction::Mul, op1, op2, "", insertAfter);
        BinaryOperator *op4 = BinaryOperator::Create(Instruction::Mul, origVar, origVar, "", insertAfter);
        BinaryOperator *op5 = BinaryOperator::Create(Instruction::Mul, op4, CONST(i32, 3), "", insertAfter);
        BinaryOperator *op6 = BinaryOperator::Create(Instruction::Mul, origVar, CONST(i32, 7), "", insertAfter);
        BinaryOperator *op7 = BinaryOperator::Create(Instruction::Sub, op3, op5, "", insertAfter);
        BinaryOperator *op8 = BinaryOperator::Create(Instruction::Add, op6, op7, "", insertAfter);
        result = op8;
    }else if(code == 2){
        //x = (x - 1) * (x + 3) - (x + 4) * (x - 3) - 9
        BinaryOperator *op1 = BinaryOperator::Create(Instruction::Sub, origVar, CONST(i32, 1), "", insertAfter);
        BinaryOperator *op2 = BinaryOperator::Create(Instruction::Add, origVar, CONST(i32, 3), "", insertAfter);
        BinaryOperator *op3 = BinaryOperator::Create(Instruction::Add, origVar, CONST(i32, 4), "", insertAfter);
        BinaryOperator *op4 = BinaryOperator::Create(Instruction::Sub, origVar, CONST(i32, 3), "", insertAfter);
        BinaryOperator *op5 = BinaryOperator::Create(Instruction::Mul, op1, op2, "", insertAfter);
        BinaryOperator *op6 = BinaryOperator::Create(Instruction::Mul, op3, op4, "", insertAfter);
        BinaryOperator *op7 = BinaryOperator::Create(Instruction::Sub, op5, op6, "", insertAfter);
        BinaryOperator *op8 = BinaryOperator::Create(Instruction::Sub, op7, CONST(i32, 9), "", insertAfter);
        result = op8;
    }
    return result;
}

Value* RandomControlFlow::insertRandomBranch(BasicBlock *IfTrue, BasicBlock *IfFalse, BasicBlock *insertAfter){
    Module *M = insertAfter->getModule();
    IntegerType *i32 = Type::getInt32Ty(M->getContext());
    /*Function *rdrand_32 = Intrinsic::getDeclaration(M, Intrinsic::x86_rdrand_32);
    CallInst *randVarStruct = CallInst::Create(rdrand_32->getFunctionType(), rdrand_32, "", insertAfter);
    Value *origRandVar = ExtractValueInst::Create(randVarStruct, 0, "", insertAfter);*/
    Function *rdrand_32 = Intrinsic::getDeclaration(M, Intrinsic::x86_rdrand_32);
    CallInst *randVarStruct = CallInst::Create(rdrand_32->getFunctionType(), rdrand_32, "", insertAfter);

    Value *origRandVar = CONST(i32, 1);
    Value *randVar = transformVar(origRandVar, insertAfter);
    Value *randMod2 = BinaryOperator::Create(Instruction::And, randVar, CONST(i32, 1), "", insertAfter);
    ICmpInst *condition = new ICmpInst(*insertAfter, ICmpInst::ICMP_EQ, randMod2, CONST(i32, 1));
    BranchInst::Create(IfTrue, IfFalse, condition, insertAfter);
    return origRandVar;
}

 bool RandomControlFlow::randcf(BasicBlock *entryBB){
    // 拆分得到 entryBB, bodyBB, endBB
    // 其中所有的 PHI 指令都在 entryBB(如果有的话)
    // endBB 只包含一条终结指令
    BasicBlock *bodyBB = entryBB->splitBasicBlock(entryBB->getFirstNonPHIOrDbgOrLifetime());
    BasicBlock *endBB = bodyBB->splitBasicBlock(bodyBB->getTerminator());
    
    // 创建 bodyBB 的变异基本块 bodyBB.altered
    BasicBlock *alteredBB = createAlteredBasicBlock(bodyBB);
    alteredBB->getTerminator()->eraseFromParent();
    BranchInst::Create(endBB, alteredBB);
    
    //在第一个基本块后插入随机跳转，使其能够随机跳转到第二个基本块或其克隆基本块
    entryBB->getTerminator()->eraseFromParent();
    Value* origRandVar = insertRandomBranch(bodyBB, alteredBB, entryBB);
    return true;
}

BasicBlock* RandomControlFlow::alterBB(BasicBlock *BB){
    for(Instruction &I : *BB){
        if(I.isBinaryOp()){
            unsigned opcode = I.getOpcode();
            BinaryOperator *op, *op1;
            if(
                opcode == Instruction::Add || opcode == Instruction::Sub || 
                opcode == Instruction::Mul || opcode == Instruction::UDiv ||
                opcode == Instruction::SDiv || opcode == Instruction::URem ||
                opcode == Instruction::SRem || opcode == Instruction::Shl ||
                opcode == Instruction::LShr || opcode == Instruction::AShr ||
                opcode == Instruction::And || opcode == Instruction::Or ||
                opcode == Instruction::Xor
            ){
                for(int random = rand() % 10;random < 10;random++){
                    switch(rand() % 4){
                        case 0:
                            break;
                        case 1: 
                            op = BinaryOperator::CreateNeg(I.getOperand(0), "", &I);
                            op1 = BinaryOperator::CreateAdd(op, I.getOperand(1), "", &I);
                            break;
                        case 2: 
                            op = BinaryOperator::CreateSub(I.getOperand(0), I.getOperand(1),"", &I);
                            op1 = BinaryOperator::CreateMul(op, I.getOperand(1), "", &I);
                            break;
                        case 3: 
                            op = BinaryOperator::CreateShl(I.getOperand(0), I.getOperand(1), "", &I);
                            break;
                    }
                }
            }else if(
                opcode == Instruction::FAdd || opcode == Instruction::FSub ||
                opcode == Instruction::FMul || opcode == Instruction::FDiv ||
                opcode == Instruction::FRem
            ){
                for(int random = rand() % 10;random < 10;random++){
                    switch(rand() % 3){
                        case 0:
                            break;
                        case 1: 
                            op = BinaryOperator::CreateNeg(I.getOperand(0), "", &I);
                            op1 = BinaryOperator::CreateFAdd(op, I.getOperand(1), "",&I);
                            break;
                        case 2: 
                            op = BinaryOperator::CreateFSub(I.getOperand(0), I.getOperand(1), "", &I);
                            op1 = BinaryOperator::CreateFMul(op, I.getOperand(1), "", &I);
                            break;
                    }
                }
            }
        }
    }
}

BasicBlock* RandomControlFlow::createAlteredBasicBlock(BasicBlock *BB){
    ValueToValueMapTy VMap;
    BasicBlock * alteredBB = CloneBasicBlock(BB, VMap, BB->getName() + ".clone", BB->getParent());
    // 对克隆基本块的引用进行修复
    for(Instruction &I : *alteredBB){
        for(int i = 0;i < I.getNumOperands();i ++){
            Value *V = MapValue(I.getOperand(i), VMap);
            if(V){
                I.setOperand(i, V);
            }
        }
    }
    // 对克隆的基本块进行变异（加入垃圾代码）
    alterBB(alteredBB);
    return alteredBB;
}

char RandomControlFlow::ID = 0;
static RegisterPass<RandomControlFlow> X("rcf", "Add random control flow to each function.");