#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Pass.h"

#define NUMBER_ADD_SUBST 4
#define NUMBER_SUB_SUBST 3
#define NUMBER_AND_SUBST 2
#define NUMBER_OR_SUBST 2
#define NUMBER_XOR_SUBST 2

namespace llvm {

class Substitution : public FunctionPass {
public:
  static char ID;
  bool enable;

  Substitution(bool enable) : FunctionPass(ID) { this->enable = enable; }

  bool runOnFunction(Function &F);

  void substitute(BinaryOperator *BI);

  // 替换 Add 指令
  void substituteAdd(BinaryOperator *BI);
  // 加法替换：a = b + c -> a = b - (-c)
  void addNeg(BinaryOperator *BI);
  // 加法替换：a = b + c -> a = -(-b + (-c))
  void addDoubleNeg(BinaryOperator *BI);
  // 加法替换：a = b + c -> r = rand (); a = b + r; a = a + c; a = a - r
  void addRand(BinaryOperator *BI);
  // 加法替换：a = b + c -> r = rand (); a = b - r; a = a + b; a = a + r
  void addRand2(BinaryOperator *BI);

  // 替换 Sub 指令
  void substituteSub(BinaryOperator *BI);
  // 减法替换：a = b - c -> a = b + (-c)
  void subNeg(BinaryOperator *BI);
  // 减法替换：a = b - c -> r = rand (); a = b + r; a = a - c; a = a - r
  void subRand(BinaryOperator *BI);
  // 减法替换：a = b - c -> a = b - r; a = a - c; a = a + r
  void subRand2(BinaryOperator *BI);

  // 替换 And 指令
  void substituteAnd(BinaryOperator *BI);
  // 与替换：a = b & c -> a = (b ^ ~c) & b
  void andSubstitute(BinaryOperator *BI);
  // 与替换：a = b & c -> a = ~(~b | ~c) & (r | ~r)
  void andSubstituteRand(BinaryOperator *BI);

  // 替换 Or 指令
  void substituteOr(BinaryOperator *BI);
  // 或替换：a = b | c -> a = (b & c) | (b ^ c)
  void orSubstitute(BinaryOperator *BI);
  // 或替换：a = b | c -> a = ~(~b & ~c) & (r | ~r)
  void orSubstituteRand(BinaryOperator *BI);

  // 替换 Xor 指令
  void substituteXor(BinaryOperator *BI);
  // 异或替换：a = b ^ c -> a = ~b & c | b & ~c
  void xorSubstitute(BinaryOperator *BI);
  // 异或替换：a = b ^ c -> (b ^ r) ^ (c ^ r) <=> (~b & r | b & ~r) ^ (~c & r |
  // c & ~r)
  void xorSubstituteRand(BinaryOperator *BI);
};

FunctionPass *createSubstitutionPass(bool enable);
} // namespace llvm