#include "llvm/Support/CommandLine.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/Obfuscation/CryptoUtils.h"
#include "llvm/Transforms/Obfuscation/MBAObfuscation.h"
#include "llvm/Transforms/Obfuscation/MBAUtils.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace llvm;
using namespace MBAUtils;

#define NUM_COEFFS 5

PreservedAnalyses Pluto::MbaObfuscation::run(Function &F, FunctionAnalysisManager &AM) {
    for (BasicBlock &BB : F) {
        std::vector<Instruction *> origInst;
        for (Instruction &I : BB) {
            origInst.push_back(&I);
        }
        for (Instruction *I : origInst) {
            if (isa<BinaryOperator>(I)) {
                BinaryOperator *BI = cast<BinaryOperator>(I);
                if (BI->getOperand(0)->getType()->isIntegerTy()) {
                    // Do not support 128-bit integers now
                    if (BI->getOperand(0)->getType()->getIntegerBitWidth() > 64) {
                        continue;
                    }
                    substitute(BI);
                }
            } else {
                for (int i = 0; i < I->getNumOperands(); i++) {
                    if (I->getOperand(0)->getType()->isIntegerTy()) {
                        // error occurs for unknown reasons
                        // if(isa<StoreInst>(I) || isa<CmpInst>(I) || isa<CallInst>(I)){
                        if (isa<StoreInst>(I) || isa<CmpInst>(I)) {
                            substituteConstant(I, i);
                        }
                    }
                }
            }
        }
    }
    PreservedAnalyses PA;
    PA.preserveSet<CFGAnalyses>();
    return PA;
}

void Pluto::MbaObfuscation::substituteConstant(Instruction *I, int i) {
    ConstantInt *val = dyn_cast<ConstantInt>(I->getOperand(i));
    if (val && val->getBitWidth() <= 64) {
        int64_t *coeffs = generateLinearMBA(NUM_COEFFS);
        coeffs[14] -= val->getValue().getZExtValue();
        Value *mbaExpr = insertLinearMBA(coeffs, I);
        delete[] coeffs;
        if (val->getBitWidth() <= 32) {
            mbaExpr = insertPolynomialMBA(mbaExpr, I);
        }
        I->setOperand(i, mbaExpr);
    }
}

void Pluto::MbaObfuscation::substitute(BinaryOperator *BI) {
    Value *mbaExpr = nullptr;
    switch (BI->getOpcode()) {
    case BinaryOperator::Add:
        mbaExpr = substituteAdd(BI);
        break;
    case BinaryOperator::Sub:
        mbaExpr = substituteSub(BI);
        break;
    case BinaryOperator::And:
        mbaExpr = substituteAnd(BI);
        break;
    case BinaryOperator::Or:
        mbaExpr = substituteOr(BI);
        break;
    case BinaryOperator::Xor:
        mbaExpr = substituteXor(BI);
        break;
    default:
        break;
    }
    if (mbaExpr) {
        if (BI->getOperand(0)->getType()->getIntegerBitWidth() <= 32) {
            mbaExpr = insertPolynomialMBA(mbaExpr, BI);
        }
        BI->replaceAllUsesWith(mbaExpr);
    }
}

Value *Pluto::MbaObfuscation::substituteAdd(BinaryOperator *BI) {
    int64_t *coeffs = generateLinearMBA(NUM_COEFFS);
    coeffs[2] += 1;
    coeffs[4] += 1;
    Value *mbaExpr = insertLinearMBA(coeffs, BI);
    delete[] coeffs;
    return mbaExpr;
}

Value *Pluto::MbaObfuscation::substituteSub(BinaryOperator *BI) {
    int64_t *coeffs = generateLinearMBA(NUM_COEFFS);
    coeffs[2] += 1;
    coeffs[4] -= 1;
    Value *mbaExpr = insertLinearMBA(coeffs, BI);
    delete[] coeffs;
    return mbaExpr;
}

Value *Pluto::MbaObfuscation::substituteXor(BinaryOperator *BI) {
    int64_t *coeffs = generateLinearMBA(NUM_COEFFS);
    coeffs[5] += 1;
    Value *mbaExpr = insertLinearMBA(coeffs, BI);
    delete[] coeffs;
    return mbaExpr;
}

Value *Pluto::MbaObfuscation::substituteAnd(BinaryOperator *BI) {
    int64_t *coeffs = generateLinearMBA(NUM_COEFFS);
    coeffs[0] += 1;
    Value *mbaExpr = insertLinearMBA(coeffs, BI);
    delete[] coeffs;
    return mbaExpr;
}

Value *Pluto::MbaObfuscation::substituteOr(BinaryOperator *BI) {
    int64_t *coeffs = generateLinearMBA(NUM_COEFFS);
    coeffs[6] += 1;
    Value *mbaExpr = insertLinearMBA(coeffs, BI);
    delete[] coeffs;
    return mbaExpr;
}