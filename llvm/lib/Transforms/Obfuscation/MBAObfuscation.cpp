
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Transforms/Obfuscation/Utils.h"
#include "llvm/Transforms/Obfuscation/MBAObfuscation.h"
#include "llvm/Transforms/Obfuscation/CryptoUtils.h"
#include "llvm/Transforms/Obfuscation/MBAUtils.h"
#include <vector>
#include <iostream>
using namespace std;
using namespace llvm;

static cl::opt<int> ObfuTimes("mba-times", cl::init(1), cl::desc("Run MBAObfuscation pass <mba-times> time(s)"));
static cl::opt<int> TermsNumber("linear-mba-terms", cl::init(10), cl::desc("Choose <linear-mba-terms> boolean exprs to construct the linear MBA expr."));

using namespace z3;

bool MBAObfuscation::runOnFunction(Function &F){
    if(enable){
        INIT_CONTEXT(F);
        for(int i = 0;i < ObfuTimes;i ++){
            for(BasicBlock &BB : F){
                std::vector<Instruction*> origInst;
                for(Instruction &I : BB){
                    origInst.push_back(&I);
                }
                for(Instruction *I : origInst){
                    if(isa<BinaryOperator>(I)){
                        BinaryOperator *BI = cast<BinaryOperator>(I);
                        if(BI->getOperand(0)->getType()->isIntegerTy()){
                            substitute(BI);
                        }
                    }
                }
            }
        }
        return true;
    }
    return false;
}

void MBAObfuscation::substitute(BinaryOperator *BI){
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


void MBAObfuscation::substituteAdd(BinaryOperator *BI){
    int64_t *terms = generateLinearMBA(TermsNumber);
    terms[2] += 1;
    terms[4] += 1;
    Value *mbaExpr = insertPolynomialMBA(insertLinearMBA(terms, BI), BI);
    BI->replaceAllUsesWith(mbaExpr);
}

void MBAObfuscation::substituteSub(BinaryOperator *BI){
    int64_t *terms = generateLinearMBA(TermsNumber);
    terms[2] += 1;
    terms[4] -= 1;
    Value *mbaExpr = insertLinearMBA(terms, BI);
    BI->replaceAllUsesWith(mbaExpr);
}

void MBAObfuscation::substituteXor(BinaryOperator *BI){
    int64_t *terms = generateLinearMBA(TermsNumber);
    terms[5] += 1;
    Value *mbaExpr = insertLinearMBA(terms, BI);
    BI->replaceAllUsesWith(mbaExpr);
}

void MBAObfuscation::substituteAnd(BinaryOperator *BI){
    int64_t *terms = generateLinearMBA(TermsNumber);
    terms[0] += 1;
    Value *mbaExpr = insertLinearMBA(terms, BI);
    BI->replaceAllUsesWith(mbaExpr);
}

void MBAObfuscation::substituteOr(BinaryOperator *BI){
    int64_t *terms = generateLinearMBA(TermsNumber);
    terms[6] += 1;
    Value *mbaExpr = insertLinearMBA(terms, BI);
    BI->replaceAllUsesWith(mbaExpr);
}

FunctionPass* llvm::createMBAObfuscationPass(bool enable){
    return new MBAObfuscation(enable);
}

char MBAObfuscation::ID = 0;