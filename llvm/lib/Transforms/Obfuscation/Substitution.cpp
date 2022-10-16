
#include "llvm/Transforms/Obfuscation/Substitution.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/Obfuscation/CryptoUtils.h"
#include "llvm/Transforms/Obfuscation/Utils.h"
#include <vector>
using namespace llvm;
using std::vector;

// 混淆次数，混淆次数越多混淆结果越复杂
static cl::opt<int>
    ObfuTimes("sub-times", cl::init(1),
              cl::desc("Run Substitution pass <sub-times> time(s)"));
static IRBuilder<> *builder = nullptr;

bool Substitution::runOnFunction(Function &F) {
  if (enable) {
    INIT_CONTEXT(F);
    SKIP_IF_SHOULD(F);
    builder = new IRBuilder<>(*CONTEXT);
    for (int i = 0; i < ObfuTimes; i++) {
      for (BasicBlock &BB : F) {
        vector<Instruction *> origInst;
        for (Instruction &I : BB) {
          origInst.push_back(&I);
        }
        for (Instruction *I : origInst) {
          if (isa<BinaryOperator>(I)) {
            BinaryOperator *BI = cast<BinaryOperator>(I);
            substitute(BI);
          }
        }
      }
    }
    return true;
  }
  return false;
}

void Substitution::substitute(BinaryOperator *BI) {
  builder->SetInsertPoint(BI);
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

void Substitution::substituteAdd(BinaryOperator *BI) {
  int choice = cryptoutils->get_uint32_t() % NUMBER_ADD_SUBST;
  switch (choice) {
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

void Substitution::addNeg(BinaryOperator *BI) {
  Value *op;
  op = builder->CreateNeg(BI->getOperand(1));
  op = builder->CreateSub(BI->getOperand(0), op);
  BI->replaceAllUsesWith(op);
}

void Substitution::addDoubleNeg(BinaryOperator *BI) {
  Value *op, *op1, *op2;
  op1 = builder->CreateNeg(BI->getOperand(0));
  op2 = builder->CreateNeg(BI->getOperand(1));
  op = builder->CreateAdd(op1, op2);
  op = builder->CreateNeg(op);
  BI->replaceAllUsesWith(op);
}

void Substitution::addRand(BinaryOperator *BI) {
  ConstantInt *r =
      (ConstantInt *)CONST(BI->getType(), cryptoutils->get_uint32_t());
  Value *op;
  op = builder->CreateAdd(BI->getOperand(0), r);
  op = builder->CreateAdd(op, BI->getOperand(1));
  op = builder->CreateSub(op, r);
  BI->replaceAllUsesWith(op);
}

void Substitution::addRand2(BinaryOperator *BI) {
  ConstantInt *r =
      (ConstantInt *)CONST(BI->getType(), cryptoutils->get_uint32_t());
  Value *op;
  op = builder->CreateSub(BI->getOperand(0), r);
  op = builder->CreateAdd(op, BI->getOperand(1));
  op = builder->CreateAdd(op, r);
  BI->replaceAllUsesWith(op);
}

void Substitution::substituteSub(BinaryOperator *BI) {
  int choice = cryptoutils->get_uint32_t() % NUMBER_SUB_SUBST;
  switch (choice) {
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

void Substitution::subNeg(BinaryOperator *BI) {
  Value *op;
  op = builder->CreateNeg(BI->getOperand(1));
  op = builder->CreateAdd(BI->getOperand(0), op);
  BI->replaceAllUsesWith(op);
}

void Substitution::subRand(BinaryOperator *BI) {
  ConstantInt *r =
      (ConstantInt *)CONST(BI->getType(), cryptoutils->get_uint32_t());
  Value *op;
  op = builder->CreateAdd(BI->getOperand(0), r);
  op = builder->CreateSub(op, BI->getOperand(1));
  op = builder->CreateSub(op, r);
  BI->replaceAllUsesWith(op);
}

void Substitution::subRand2(BinaryOperator *BI) {
  ConstantInt *r =
      (ConstantInt *)CONST(BI->getType(), cryptoutils->get_uint32_t());
  Value *op;
  op = builder->CreateSub(BI->getOperand(0), r);
  op = builder->CreateSub(op, BI->getOperand(1));
  op = builder->CreateAdd(op, r);
  BI->replaceAllUsesWith(op);
}

void Substitution::substituteXor(BinaryOperator *BI) {
  int choice = cryptoutils->get_uint32_t() % NUMBER_XOR_SUBST;
  switch (choice) {
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

void Substitution::xorSubstitute(BinaryOperator *BI) {
  Value *op, *op1, *op2, *op3;
  op1 = builder->CreateNot(BI->getOperand(0));
  op1 = builder->CreateAnd(op1, BI->getOperand(1));
  op2 = builder->CreateNot(BI->getOperand(1));
  op2 = builder->CreateAnd(BI->getOperand(0), op2);
  op = builder->CreateOr(op1, op2);
  BI->replaceAllUsesWith(op);
}

void Substitution::xorSubstituteRand(BinaryOperator *BI) {
  ConstantInt *r =
      (ConstantInt *)CONST(BI->getType(), cryptoutils->get_uint32_t());
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

void Substitution::substituteAnd(BinaryOperator *BI) {
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

void Substitution::andSubstitute(BinaryOperator *BI) {
  Value *op;
  op = builder->CreateNot(BI->getOperand(1));
  op = builder->CreateXor(BI->getOperand(0), op);
  op = builder->CreateAnd(op, BI->getOperand(0));
  BI->replaceAllUsesWith(op);
}

void Substitution::andSubstituteRand(BinaryOperator *BI) {
  ConstantInt *r =
      (ConstantInt *)CONST(BI->getType(), cryptoutils->get_uint32_t());
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

void Substitution::substituteOr(BinaryOperator *BI) {
  int choice = cryptoutils->get_uint32_t() % NUMBER_OR_SUBST;
  switch (choice) {
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

void Substitution::orSubstitute(BinaryOperator *BI) {
  Value *op, *op1;
  op = builder->CreateAnd(BI->getOperand(0), BI->getOperand(1));
  op1 = builder->CreateXor(BI->getOperand(0), BI->getOperand(1));
  op = builder->CreateOr(op, op1);
  BI->replaceAllUsesWith(op);
}

void Substitution::orSubstituteRand(BinaryOperator *BI) {
  ConstantInt *r =
      (ConstantInt *)CONST(BI->getType(), cryptoutils->get_uint32_t());
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

FunctionPass *llvm::createSubstitutionPass(bool enable) {
  return new Substitution(enable);
}

char Substitution::ID = 0;