#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Transforms/Utils/ValueMapper.h"
#include "llvm/Transforms/Utils/Cloning.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Instructions.h"
#include "SplitBasicBlock.h"
#include <vector>
#include <cstdlib>
#include <ctime>
using std::vector;
using namespace llvm;

// 混淆次数，混淆次数越多混淆结果越复杂
static cl::opt<int> obfuTimes("bcf_loop", cl::init(1), cl::desc("Obfuscate a function <bcf_loop> time(s)."));

namespace{
    class BogusControlFlow : public FunctionPass {
        public:
            static char ID;
            BogusControlFlow() : FunctionPass(ID) {}

            bool runOnFunction(Function &F);

            // 创建基本块 BB 的变异基本块
            // 第一步：克隆基本块BB
            // 第二步：向克隆出的基本块中的若干指令中的操作数进行修改，并添加无用指令，得到变异基本块
            // 注意变异基本块与原基本块不是等价的！！！
            BasicBlock* createAlteredBasicBlock(BasicBlock *BB);

            // 对基本块 BB 进行混淆
            void bogus(BasicBlock *BB);

            // 使基本块发生变异：
            // 1. 对基本块中的若干指令中的操作数进行修改
            // 2. 向基本块中添加无用指令
            BasicBlock* alterBB(BasicBlock *BB);

            // 创建代表一个永真式的 ICmpInst*
            // 该永真式为：y < 10 || x * (x + 1) % 2 == 0
            // 其中 x, y 为恒为0的全局变量
            Value* createBogusCondition(Instruction *term);
    };

}

bool BogusControlFlow::runOnFunction(Function &F){
    FunctionPass *pass = createSplitBasicBlockPass();
    pass->runOnFunction(F);
    for(int i = 0;i < obfuTimes;i ++){
        vector<BasicBlock*> origBB;
        for(BasicBlock &BB : F){
            origBB.push_back(&BB);
        }
        for(BasicBlock *BB : origBB){
            bogus(BB);
        }
    }
    return true;
}

BasicBlock* BogusControlFlow::createAlteredBasicBlock(BasicBlock *BB){
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
    // 对克隆的基本块进行变异（加入垃圾代码，修改指令操作符等等）
    alterBB(alteredBB);
    return alteredBB;
}

BasicBlock* BogusControlFlow::alterBB(BasicBlock *BB){
    srand(time(NULL));
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
            }else if(opcode == Instruction::ICmp){
                ICmpInst *cmpI = cast<ICmpInst>(&I);
                switch(rand() % 3){
                    case 0:
                        break;
                    case 1: 
                        cmpI->swapOperands();
                        break;
                    case 2: // randomly change the predicate
                        switch(rand() % 10){
                            case 0: cmpI->setPredicate(ICmpInst::ICMP_EQ);
                                break; // equal
                            case 1: cmpI->setPredicate(ICmpInst::ICMP_NE);
                                break; // not equal
                            case 2: cmpI->setPredicate(ICmpInst::ICMP_UGT);
                                break; // unsigned greater than
                            case 3: cmpI->setPredicate(ICmpInst::ICMP_UGE);
                                break; // unsigned greater or equal
                            case 4: cmpI->setPredicate(ICmpInst::ICMP_ULT);
                                break; // unsigned less than
                            case 5: cmpI->setPredicate(ICmpInst::ICMP_ULE);
                                break; // unsigned less or equal
                            case 6: cmpI->setPredicate(ICmpInst::ICMP_SGT);
                                break; // signed greater than
                            case 7: cmpI->setPredicate(ICmpInst::ICMP_SGE);
                                break; // signed greater or equal
                            case 8: cmpI->setPredicate(ICmpInst::ICMP_SLT);
                                break; // signed less than
                            case 9: cmpI->setPredicate(ICmpInst::ICMP_SLE);
                                break; // signed less or equal
                        }
                        break;
                }
            }else if(opcode == Instruction::FCmp){ // Conditions (with float)
                FCmpInst *cmpI = cast<FCmpInst>(&I);
                switch(rand() % 3){ // must be improved
                    case 0: //do nothing
                        break;
                    case 1: cmpI->swapOperands();
                        break;
                    case 2: // randomly change the predicate
                        switch(rand() % 10){
                            case 0: cmpI->setPredicate(FCmpInst::FCMP_OEQ);
                                break; // ordered and equal
                            case 1: cmpI->setPredicate(FCmpInst::FCMP_ONE);
                                break; // ordered and operands are unequal
                            case 2: cmpI->setPredicate(FCmpInst::FCMP_UGT);
                                break; // unordered or greater than
                            case 3: cmpI->setPredicate(FCmpInst::FCMP_UGE);
                                break; // unordered, or greater than, or equal
                            case 4: cmpI->setPredicate(FCmpInst::FCMP_ULT);
                                break; // unordered or less than
                            case 5: cmpI->setPredicate(FCmpInst::FCMP_ULE);
                                break; // unordered, or less than, or equal
                            case 6: cmpI->setPredicate(FCmpInst::FCMP_OGT);
                                break; // ordered and greater than
                            case 7: cmpI->setPredicate(FCmpInst::FCMP_OGE);
                                break; // ordered and greater than or equal
                            case 8: cmpI->setPredicate(FCmpInst::FCMP_OLT);
                                break; // ordered and less than
                            case 9: cmpI->setPredicate(FCmpInst::FCMP_OLE);
                                break; // ordered or less than, or equal
                        }
                        break;
                }
            }
        }
    }
}

#define CONST(T,V) ConstantInt::get(T, V, false)


Value* BogusControlFlow::createBogusCondition(Instruction *term){
    // if((y < 10 || x * (x + 1) % 2 == 0))
    // 等价于 if(true)
    Module *M = term->getModule();
    IntegerType *i32 = Type::getInt32Ty(M->getContext());
    GlobalVariable *xptr = new GlobalVariable(*M, i32, false, GlobalValue::CommonLinkage, CONST(i32, 0), "x");
    GlobalVariable *yptr = new GlobalVariable(*M, i32, false, GlobalValue::CommonLinkage, CONST(i32, 0), "y");
    LoadInst *x = new LoadInst(i32, xptr, "", term);
    LoadInst *y = new LoadInst(i32, yptr, "", term);
    ICmpInst *cond1 = new ICmpInst(term, CmpInst::ICMP_SLT, y, CONST(i32, 10));
    BinaryOperator *op = BinaryOperator::CreateAdd(x, CONST(i32, 1), "", term);
    op = BinaryOperator::CreateMul(op, x, "", term);
    op = BinaryOperator::CreateURem(op, CONST(i32, 2), "", term);
    ICmpInst *cond2 = new ICmpInst(term, CmpInst::ICMP_EQ, op, CONST(i32, 0));
    return BinaryOperator::CreateOr(cond1, cond2, "", term);
}

void BogusControlFlow::bogus(BasicBlock *entryBB){
    // 拆分得到 entryBB, bodyBB, endBB
    // 其中所有的 PHI 指令都在 entryBB(如果有的话)
    // endBB 只包含一条终结指令
    BasicBlock *bodyBB = entryBB->splitBasicBlock(entryBB->getFirstNonPHIOrDbgOrLifetime());
    BasicBlock *endBB = bodyBB->splitBasicBlock(bodyBB->getTerminator());
    
    // 创建 bodyBB 的变异基本块 bodyBB.altered
    BasicBlock *alteredBB = createAlteredBasicBlock(bodyBB);

    // 添加虚假跳转
    // 1. 创建恒为真的条件
    Value *cond1 = createBogusCondition(entryBB->getTerminator()); 
    Value *cond2 = createBogusCondition(bodyBB->getTerminator()); 
    // 2. 将entryBB, bodyBB, alteredBB 末尾的绝对跳转移除
    entryBB->getTerminator()->eraseFromParent();
    bodyBB->getTerminator()->eraseFromParent();
    alteredBB->getTerminator()->eraseFromParent();
    // 将 entryBB 到 bodyBB 的绝对跳转改为条件跳转
    BranchInst::Create(bodyBB, alteredBB, cond1, entryBB);
    // 将 bodyBB 到 endBB的绝对跳转改为条件跳转
    BranchInst::Create(endBB, alteredBB, cond2, bodyBB);
    // 添加 bodyBB.altered 到 bodyBB 的绝对跳转
    BranchInst::Create(bodyBB, alteredBB);
}

char BogusControlFlow::ID = 0;
static RegisterPass<BogusControlFlow> X("bcf", "Add bogus control flow to each function.");