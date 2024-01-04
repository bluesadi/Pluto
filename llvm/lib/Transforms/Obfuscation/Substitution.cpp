#include "llvm/IR/IRBuilder.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/Obfuscation/CryptoUtils.h"
#include "llvm/Transforms/Obfuscation/Substitution.h"
#include <vector>

using namespace llvm;
using std::vector;

static IRBuilder<> *builder = nullptr;

PreservedAnalyses Pluto::Substitution::run(Function &F, FunctionAnalysisManager &AM) {
    builder = new IRBuilder<>(F.getContext());
    for (BasicBlock &BB : F) {
        vector<Instruction *> origInst;
        for (Instruction &I : BB) {
            origInst.push_back(&I);
        }
        for (Instruction *I : origInst) {
            if (BinaryOperator *BI = dyn_cast<BinaryOperator>(I)) {
                builder->SetInsertPoint(BI);
                substitute(BI);
            }
        }
    }
    PreservedAnalyses PA;
    PA.preserveSet<CFGAnalyses>();
    return PA;
}

void Pluto::Substitution::substitute(BinaryOperator *BI) {
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
        break;
    }
}

void Pluto::Substitution::substituteAdd(BinaryOperator *BI) {
    switch (cryptoutils->get_range(4)) {
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

void Pluto::Substitution::addNeg(BinaryOperator *BI) {
    Value *op;
    op = builder->CreateNeg(BI->getOperand(1));
    op = builder->CreateSub(BI->getOperand(0), op);
    BI->replaceAllUsesWith(op);
}

void Pluto::Substitution::addDoubleNeg(BinaryOperator *BI) {
    Value *op, *op1, *op2;
    op1 = builder->CreateNeg(BI->getOperand(0));
    op2 = builder->CreateNeg(BI->getOperand(1));
    op = builder->CreateAdd(op1, op2);
    op = builder->CreateNeg(op);
    BI->replaceAllUsesWith(op);
}

void Pluto::Substitution::addRand(BinaryOperator *BI) {
    Constant *r = ConstantInt::get(BI->getType(), cryptoutils->get_uint32_t());
    Value *op;
    op = builder->CreateAdd(BI->getOperand(0), r);
    op = builder->CreateAdd(op, BI->getOperand(1));
    op = builder->CreateSub(op, r);
    BI->replaceAllUsesWith(op);
}

void Pluto::Substitution::addRand2(BinaryOperator *BI) {
    Constant *r = ConstantInt::get(BI->getType(), cryptoutils->get_uint32_t());
    Value *op;
    op = builder->CreateSub(BI->getOperand(0), r);
    op = builder->CreateAdd(op, BI->getOperand(1));
    op = builder->CreateAdd(op, r);
    BI->replaceAllUsesWith(op);
}

void Pluto::Substitution::substituteSub(BinaryOperator *BI) {
    switch (cryptoutils->get_range(3)) {
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

void Pluto::Substitution::subNeg(BinaryOperator *BI) {
    Value *op;
    op = builder->CreateNeg(BI->getOperand(1));
    op = builder->CreateAdd(BI->getOperand(0), op);
    BI->replaceAllUsesWith(op);
}

void Pluto::Substitution::subRand(BinaryOperator *BI) {
    Constant *r = ConstantInt::get(BI->getType(), cryptoutils->get_uint32_t());
    Value *op;
    op = builder->CreateAdd(BI->getOperand(0), r);
    op = builder->CreateSub(op, BI->getOperand(1));
    op = builder->CreateSub(op, r);
    BI->replaceAllUsesWith(op);
}

void Pluto::Substitution::subRand2(BinaryOperator *BI) {
    Constant *r = ConstantInt::get(BI->getType(), cryptoutils->get_uint32_t());
    Value *op;
    op = builder->CreateSub(BI->getOperand(0), r);
    op = builder->CreateSub(op, BI->getOperand(1));
    op = builder->CreateAdd(op, r);
    BI->replaceAllUsesWith(op);
}

void Pluto::Substitution::substituteXor(BinaryOperator *BI) {
    int choice = cryptoutils->get_uint32_t() % NUMBER_XOR_SUBST;
    switch (cryptoutils->get_range(2)) {
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

void Pluto::Substitution::xorSubstitute(BinaryOperator *BI) {
    Value *op, *op1, *op2, *op3;
    op1 = builder->CreateNot(BI->getOperand(0));
    op1 = builder->CreateAnd(op1, BI->getOperand(1));
    op2 = builder->CreateNot(BI->getOperand(1));
    op2 = builder->CreateAnd(BI->getOperand(0), op2);
    op = builder->CreateOr(op1, op2);
    BI->replaceAllUsesWith(op);
}

void Pluto::Substitution::xorSubstituteRand(BinaryOperator *BI) {
    Constant *r = ConstantInt::get(BI->getType(), cryptoutils->get_uint32_t());
    Value *op, *op1, *op2, *op3;
    op1 = builder->CreateNot(BI->getOperand(0));
    op1 = builder->CreateAnd(op1, r);
    op2 = builder->CreateNot(r);
    op2 = builder->CreateAnd(BI->getOperand(0), op2);
    op = builder->CreateOr(op1, op2);
    op1 = builder->CreateNot(BI->getOperand(1));
    op1 = builder->CreateAnd(op1, r);
    op2 = builder->CreateNot(r);
    op2 = builder->CreateAnd(BI->getOperand(1), op2);
    op3 = builder->CreateOr(op1, op2);
    op = builder->CreateXor(op, op3);
    BI->replaceAllUsesWith(op);
}

void Pluto::Substitution::substituteAnd(BinaryOperator *BI) {
    int choice = cryptoutils->get_uint32_t() % NUMBER_AND_SUBST;
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

void Pluto::Substitution::andSubstitute(BinaryOperator *BI) {
    Value *op;
    op = builder->CreateNot(BI->getOperand(1));
    op = builder->CreateXor(BI->getOperand(0), op);
    op = builder->CreateAnd(op, BI->getOperand(0));
    BI->replaceAllUsesWith(op);
}

void Pluto::Substitution::andSubstituteRand(BinaryOperator *BI) {
    Constant *r = ConstantInt::get(BI->getType(), cryptoutils->get_uint32_t());
    Value *op, *op1;
    op = builder->CreateNot(BI->getOperand(0));
    op1 = builder->CreateNot(BI->getOperand(1));
    op = builder->CreateOr(op, op1);
    op = builder->CreateNot(op);
    op1 = builder->CreateNot(r);
    op1 = builder->CreateOr(r, op1);
    op = builder->CreateAnd(op, op1);
    BI->replaceAllUsesWith(op);
}

void Pluto::Substitution::substituteOr(BinaryOperator *BI) {
    switch (cryptoutils->get_range(2)) {
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

void Pluto::Substitution::orSubstitute(BinaryOperator *BI) {
    Value *op, *op1;
    op = builder->CreateAnd(BI->getOperand(0), BI->getOperand(1));
    op1 = builder->CreateXor(BI->getOperand(0), BI->getOperand(1));
    op = builder->CreateOr(op, op1);
    BI->replaceAllUsesWith(op);
}

void Pluto::Substitution::orSubstituteRand(BinaryOperator *BI) {
    Constant *r = ConstantInt::get(BI->getType(), cryptoutils->get_uint32_t());
    Value *op, *op1;
    op = builder->CreateNot(BI->getOperand(0));
    op1 = builder->CreateNot(BI->getOperand(1));
    op = builder->CreateAnd(op, op1);
    op = builder->CreateNot(op);
    op1 = builder->CreateNot(r);
    op1 = builder->CreateOr(r, op1);
    op = builder->CreateAnd(op, op1);
    BI->replaceAllUsesWith(op);
}