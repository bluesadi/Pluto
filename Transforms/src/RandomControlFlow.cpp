#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Transforms/Utils/ValueMapper.h"
#include "llvm/Transforms/Utils/Cloning.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Instructions.h"
#include <vector>
#include <cstdlib>
#include <ctime>
using std::vector;
using namespace llvm;

// 混淆次数，混淆次数越多混淆结果越复杂
static cl::opt<int> ObfuTime("obfu_time", cl::init(1), cl::desc("Obfuscate <obfu_time> time(s)."));

namespace{
     class RandomControlFlow : public FunctionPass{
        static char ID;

        RandomControlFlow() : FunctionPass(ID){
            srand(time(NULL));
        }

        BasicBlock* createCloneBasicBlock(BasicBlock *BB);

        Value* transformVar(Value *origVar,BasicBlock *insertAfter);

        /*
        * 插入随机跳转
        */
        Value* insertRandomBranch(BasicBlock *BB, BasicBlock *IfTrue, BasicBlock *IfFalse){
            Function *F = BB->getParent();
            Function *randFunc = Intrinsic::getDeclaration(F->getParent(), Intrinsic::x86_rdrand_32);
            CallInst *randVarStruct = CallInst::Create(randFunc->getFunctionType(), randFunc, "", BB);
            Value *origRandVar = ExtractValueInst::Create(randVarStruct, 0, "", BB);
            Value *randVar = identicalTransform(origRandVar, BB);
            Value *randMod2 = BinaryOperator::Create(Instruction::And, randVar, getConstant(1), "", BB);
            ICmpInst *condition = new ICmpInst(*BB, ICmpInst::ICMP_EQ, randMod2, getConstant(1));
            BranchInst::Create(IfTrue, IfFalse, condition, BB);
            return origRandVar;
        }

        bool obfuscateBB(BasicBlock *BB){
            //将一个基本块分裂成两个基本块，并对第二个基本块进行复制
            BasicBlock *origBB = BB->splitBasicBlock(BB->getFirstNonPHIOrDbgOrLifetime(), "origBB");
            BasicBlock *cloneBB = createCloneBasicBlock(origBB);
            BasicBlock *headBB = BB;
            
            //在第一个基本块后插入随机跳转，使其能够随机跳转到第二个基本块或其克隆基本块
            headBB->getTerminator()->removeFromParent();
            Value* origRandVar = insertRandomBranch(BB, origBB, cloneBB);

            //如果基本块末尾是绝对跳转
            if(origBB->getTerminator()->getNumSuccessors() == 1){
                BasicBlock *origSucc = origBB->getTerminator()->getSuccessor(0);
                BasicBlock *cloneSucc = cloneBB->getTerminator()->getSuccessor(0);

                origBB->getTerminator()->eraseFromParent();
                cloneBB->getTerminator()->eraseFromParent();
                Value* randVar = identicalTransform(origRandVar, origBB);
                Value *randMod2 = BinaryOperator::Create(Instruction::And, randVar, ConstantInt::get(TYPE_INT32, 1), "", origBB);
                ICmpInst *condition = new ICmpInst(*origBB, ICmpInst::ICMP_EQ, randMod2, getConstant(0));
                BranchInst::Create(cloneBB, origSucc, condition, origBB);

                randVar = identicalTransform(origRandVar, cloneBB);
                randMod2 = BinaryOperator::Create(Instruction::And, randVar, getConstant(1), "", cloneBB);
                condition = new ICmpInst(*cloneBB, ICmpInst::ICMP_EQ, randMod2, getConstant(1));
                BranchInst::Create(origBB, cloneSucc, condition, cloneBB);
            }
            return true;
        }

        bool runOnFunction(Function &F){
            TYPE_INT32 = Type::getInt32Ty(F.getContext());
            bool flag = true;

            //保存除入口块之外的所有基本块
            vector<BasicBlock*> origBBs;
            for(BasicBlock &BB : F){
                origBBs.push_back(&BB);
            }
            origBBs.erase(origBBs.begin());
            vector<BasicBlock*> BBs;
            //分别混淆每个基本块
            for(BasicBlock *BB : BBs){
                flag = flag && obfuscateBB(BB);
            }
            return flag;
        }

    };
}

//插入随机恒等变换
Value* RandomControlFlow::transformVar(Value *origVar,BasicBlock *insertAfter){
    IntegerType *i32 = Type::getInt32Ty(origVar->getContext());
    int code = rand() % 3;
    Value *result;
    if(code == 0){
        //x = x * (x + 1) - x^2
        ConstantInt *C1 = ConstantInt::get(i32, 1, false);
        BinaryOperator *op1 = BinaryOperator::Create(Instruction::Add, origVar, C1, "", insertAfter);
        BinaryOperator *op2 = BinaryOperator::Create(Instruction::Mul, origVar, op1, "", insertAfter);
        BinaryOperator *op3 = BinaryOperator::Create(Instruction::Mul, origVar, origVar, "", insertAfter);
        BinaryOperator *op4 = BinaryOperator::Create(Instruction::Sub, op2, op3, "", insertAfter);
        result = op4;
    }else if(code == 1){
        //x = 3 * x * (x - 2) - 3 * x^2 + 7 * x
        ConstantInt *C1 = ConstantInt::get(i32, 1, false);
        ConstantInt *C2 = ConstantInt::get(i32, 2, false);
        ConstantInt *C3 = ConstantInt::get(i32, 3, false);
        ConstantInt *C7 = ConstantInt::get(i32, 7, false);
        BinaryOperator *op1 = BinaryOperator::Create(Instruction::Mul, origVar, C3, "", insertAfter);
        BinaryOperator *op2 = BinaryOperator::Create(Instruction::Sub, origVar, C2, "", insertAfter);
        BinaryOperator *op3 = BinaryOperator::Create(Instruction::Mul, op1, op2, "", insertAfter);
        BinaryOperator *op4 = BinaryOperator::Create(Instruction::Mul, origVar, origVar, "", insertAfter);
        BinaryOperator *op5 = BinaryOperator::Create(Instruction::Mul, op4, C3, "", insertAfter);
        BinaryOperator *op6 = BinaryOperator::Create(Instruction::Mul, origVar, C7, "", insertAfter);
        BinaryOperator *op7 = BinaryOperator::Create(Instruction::Sub, op3, op5, "", insertAfter);
        BinaryOperator *op8 = BinaryOperator::Create(Instruction::Add, op6, op7, "", insertAfter);
        result = op8;
    }else if(code == 2){
        //x = (x - 1) * (x + 3) - (x + 4) * (x - 3) - 9
        ConstantInt *C1 = ConstantInt::get(i32, 1, false);
        ConstantInt *C3 = ConstantInt::get(i32, 3, false);
        ConstantInt *C4 = ConstantInt::get(i32, 4, false);
        ConstantInt *C9 = ConstantInt::get(i32, 9, false);
        BinaryOperator *op1 = BinaryOperator::Create(Instruction::Sub, origVar, C1, "", insertAfter);
        BinaryOperator *op2 = BinaryOperator::Create(Instruction::Add, origVar, C3, "", insertAfter);
        BinaryOperator *op3 = BinaryOperator::Create(Instruction::Add, origVar, C4, "", insertAfter);
        BinaryOperator *op4 = BinaryOperator::Create(Instruction::Sub, origVar, C3, "", insertAfter);
        BinaryOperator *op5 = BinaryOperator::Create(Instruction::Mul, op1, op2, "", insertAfter);
        BinaryOperator *op6 = BinaryOperator::Create(Instruction::Mul, op3, op4, "", insertAfter);
        BinaryOperator *op7 = BinaryOperator::Create(Instruction::Sub, op5, op6, "", insertAfter);
        BinaryOperator *op8 = BinaryOperator::Create(Instruction::Sub, op7, C9, "", insertAfter);
        result = op8;
    }
    return result;
}

// 创建基本块 BB 的克隆基本块
// 两个基本块是等价的
BasicBlock* RandomControlFlow::createCloneBasicBlock(BasicBlock *BB){
    ValueToValueMapTy VMap;
    BasicBlock * cloneBB = CloneBasicBlock(BB, VMap, BB->getName() + ".clone", BB->getParent());
    for(Instruction &I : *cloneBB){
        for(int i = 0;i < I.getNumOperands();i ++){
            Value *V = MapValue(I.getOperand(i), VMap);
            if(V){
                I.setOperand(i, V);
            }
        }
        if (PHINode *PN = dyn_cast<PHINode>(&I)) {
            for (int i = 0; i < PN->getNumIncomingValues();i ++) {
                Value *v = MapValue(PN->getIncomingBlock(i), VMap, RF_None, 0);
                if (v != 0){
                    PN->setIncomingBlock(i, cast<BasicBlock>(v));
                }
            }
        }
    }
    return cloneBB;
}

char RandomControlFlow::ID = 0;
static RegisterPass<RandomControlFlow> X("rcf", "An obfuscation transformation similar to OLLVM Bogus Control Flow by 34r7hm4n.");