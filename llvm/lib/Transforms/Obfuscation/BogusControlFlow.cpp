#include "llvm/IR/IRBuilder.h"
#include "llvm/Transforms/Obfuscation/BogusControlFlow.h"
#include "llvm/Transforms/Utils/Cloning.h"
#include "llvm/Transforms/Utils/ValueMapper.h"
#include <vector>

using namespace llvm;

namespace Pluto {

BasicBlock *cloneBasicBlock(BasicBlock *BB) {
    ValueToValueMapTy VMap;
    BasicBlock *cloneBB = CloneBasicBlock(BB, VMap, "cloneBB", BB->getParent());
    BasicBlock::iterator origI = BB->begin();
    // 对克隆基本块的引用进行修复
    for (Instruction &I : *cloneBB) {
        for (int i = 0; i < I.getNumOperands(); i++) {
            Value *V = MapValue(I.getOperand(i), VMap);
            if (V) {
                I.setOperand(i, V);
            }
        }
        SmallVector<std::pair<unsigned, MDNode *>, 4> MDs;
        I.getAllMetadata(MDs);
        for (std::pair<unsigned, MDNode *> pair : MDs) {
            MDNode *MD = MapMetadata(pair.second, VMap);
            if (MD) {
                I.setMetadata(pair.first, MD);
            }
        }
        I.setDebugLoc(origI->getDebugLoc());
        origI++;
    }
    return cloneBB;
}

Value *createBogusCmp(BasicBlock *insertAfter) {
    // if((y < 10 || x * (x + 1) % 2 == 0))
    Module *M = insertAfter->getModule();
    LLVMContext &context = M->getContext();
    GlobalVariable *xptr = new GlobalVariable(*M, Type::getInt32Ty(context), false, GlobalValue::CommonLinkage,
                                              ConstantInt::get(Type::getInt32Ty(context), 0), "x");
    GlobalVariable *yptr = new GlobalVariable(*M, Type::getInt32Ty(context), false, GlobalValue::CommonLinkage,
                                              ConstantInt::get(Type::getInt32Ty(context), 0), "y");

    IRBuilder<> builder(context);
    builder.SetInsertPoint(insertAfter);
    LoadInst *x = builder.CreateLoad(Type::getInt32Ty(context), xptr);
    // LoadInst *y = builder.CreateLoad(Type::getInt32Ty(context), yptr);
    // Value *cond1 = builder.CreateICmpSLT(y, ConstantInt::get(Type::getInt32Ty(context), 10));
    // Value *op1 = builder.CreateAdd(x, ConstantInt::get(Type::getInt32Ty(context), 1));
    // Value *op2 = builder.CreateMul(op1, x);
    // Value *op3 = builder.CreateURem(op2, ConstantInt::get(Type::getInt32Ty(context), 2));
    // Value *cond2 = builder.CreateICmpEQ(op3, ConstantInt::get(Type::getInt32Ty(context), 0));
    // return BinaryOperator::CreateOr(cond1, cond2, "", insertAfter);
    return builder.CreateICmpSGE(x, ConstantInt::get(Type::getInt32Ty(context), 0));
}

PreservedAnalyses Pluto::BogusControlFlow::run(Function &F, FunctionAnalysisManager &AM) {
    std::vector<BasicBlock *> origBB;
    for (BasicBlock &BB : F) {
        origBB.push_back(&BB);
    }
    for (BasicBlock *BB : origBB) {
        if (isa<InvokeInst>(BB->getTerminator()) || BB->isEHPad()) {
            continue;
        }
        // 第一步，拆分得到 headBB, bodyBB, endBB
        // 其中所有的 PHI 指令都在 entryBB(如果有的话)
        // endBB 只包含一条终结指令
        BasicBlock *headBB = BB;
        BasicBlock *bodyBB = BB->splitBasicBlock(BB->getFirstNonPHIOrDbgOrLifetime(), "bodyBB");
        BasicBlock *tailBB = bodyBB->splitBasicBlock(bodyBB->getTerminator(), "endBB");
        // 第二步，克隆 bodyBB 得到克隆块 cloneBB
        BasicBlock *cloneBB = cloneBasicBlock(bodyBB);

        // 第三步，构造虚假跳转
        // 1. 将 entryBB, bodyBB, cloneBB 末尾的绝对跳转移除
        BB->getTerminator()->eraseFromParent();
        bodyBB->getTerminator()->eraseFromParent();
        cloneBB->getTerminator()->eraseFromParent();
        // 2. 在 entryBB 和 bodyBB 的末尾插入条件恒为真的虚假比较指令
        Value *cond1 = createBogusCmp(BB);
        Value *cond2 = createBogusCmp(bodyBB);
        // 3. 将 entryBB 到 bodyBB 的绝对跳转改为条件跳转
        BranchInst::Create(bodyBB, cloneBB, cond1, BB);
        // 4. 将 bodyBB 到 endBB的绝对跳转改为条件跳转
        BranchInst::Create(tailBB, cloneBB, cond2, bodyBB);
        // 5. 添加 bodyBB.clone 到 bodyBB 的绝对跳转
        BranchInst::Create(bodyBB, cloneBB);
    }
    return PreservedAnalyses::all();
}

}; // namespace Pluto