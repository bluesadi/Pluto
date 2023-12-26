#pragma once

#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Pass.h"
#include "llvm/Passes/PassBuilder.h"

#define NUMBER_ADD_SUBST 4
#define NUMBER_SUB_SUBST 3
#define NUMBER_AND_SUBST 2
#define NUMBER_OR_SUBST 2
#define NUMBER_XOR_SUBST 2

using namespace llvm;

namespace Pluto {

struct Substitution : PassInfoMixin<Substitution> {

    PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM);

    static bool isRequired() { return true; }

    void substitute(BinaryOperator *BI);

    // Substituete Add
    void substituteAdd(BinaryOperator *BI);

    // Pattern-1: a = b + c -> a = b - (-c)
    void addNeg(BinaryOperator *BI);

    // Pattern-2：a = b + c -> a = -(-b + (-c))
    void addDoubleNeg(BinaryOperator *BI);

    // Pattern-3：a = b + c -> r = rand (); a = b + r; a = a + c; a = a - r
    void addRand(BinaryOperator *BI);

    // Pattern-4：a = b + c -> r = rand (); a = b - r; a = a + b; a = a + r
    void addRand2(BinaryOperator *BI);

    // Substitute Sub
    void substituteSub(BinaryOperator *BI);

    // Pattern-1：a = b - c -> a = b + (-c)
    void subNeg(BinaryOperator *BI);

    // Pattern-2：a = b - c -> r = rand (); a = b + r; a = a - c; a = a - r
    void subRand(BinaryOperator *BI);

    // Pattern-3：a = b - c -> a = b - r; a = a - c; a = a + r
    void subRand2(BinaryOperator *BI);

    // Substitute And
    void substituteAnd(BinaryOperator *BI);

    // Pattern-1：a = b & c -> a = (b ^ ~c) & b
    void andSubstitute(BinaryOperator *BI);

    // Pattern-2：a = b & c -> a = ~(~b | ~c) & (r | ~r)
    void andSubstituteRand(BinaryOperator *BI);

    // Substitute Or
    void substituteOr(BinaryOperator *BI);

    // Pattern-1：a = b | c -> a = (b & c) | (b ^ c)
    void orSubstitute(BinaryOperator *BI);

    // Pattern-2：a = b | c -> a = ~(~b & ~c) & (r | ~r)
    void orSubstituteRand(BinaryOperator *BI);

    // Substitute Xor
    void substituteXor(BinaryOperator *BI);

    // Pattern-1：a = b ^ c -> a = ~b & c | b & ~c
    void xorSubstitute(BinaryOperator *BI);

    // Pattern-2：a = b ^ c -> (b ^ r) ^ (c ^ r) <=> (~b & r | b & ~r) ^ (~c & r | c & ~r)
    void xorSubstituteRand(BinaryOperator *BI);
};

} // namespace Pluto