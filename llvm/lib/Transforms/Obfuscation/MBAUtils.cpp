#include "z3++.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Support/FormatVariadic.h"
#include "llvm/Transforms/Obfuscation/CryptoUtils.h"
#include "llvm/Transforms/Obfuscation/MBAUtils.h"
#include <algorithm>
#include <cstdint>
#include <queue>
#include <string>
#include <vector>

#define USE_CACHE

using namespace z3;
using namespace llvm;

static int8_t truthTables[15][4] = {
    {0, 0, 0, 1}, // x & y
    {0, 0, 1, 0}, // x & ~y
    {0, 0, 1, 1}, // x
    {0, 1, 0, 0}, // ~x & y
    {0, 1, 0, 1}, // y
    {0, 1, 1, 0}, // x ^ y
    {0, 1, 1, 1}, // x | y
    {1, 0, 0, 0}, // ~(x | y)
    {1, 0, 0, 1}, // ~(x ^ y)
    {1, 0, 1, 0}, // ~y
    {1, 0, 1, 1}, // x | ~y
    {1, 1, 0, 0}, // ~x
    {1, 1, 0, 1}, // ~x | y
    {1, 1, 1, 0}, // ~(x & y)
    {1, 1, 1, 1}, // -1
};

int64_t *MBAUtils::generateLinearMBA(int numExprs) {
#ifdef USE_CACHE
    static std::queue<int64_t *> cached_coeffs;
    if (cached_coeffs.size() && cryptoutils->get_range(100) < 80) {
        int64_t *coeffs = cached_coeffs.front();
        cached_coeffs.pop();
        int64_t *coeffs_copy = new int64_t[15];
        std::copy(coeffs, coeffs + 15, coeffs_copy);
        cached_coeffs.push(coeffs_copy);
        return coeffs;
    }
#endif
    int *exprs = new int[numExprs];
    int64_t *coeffs = new int64_t[15];
    while (true) {
        context c;
        std::vector<expr> X;
        solver s(c);
        std::fill_n(coeffs, 15, 0);
        for (int i = 0; i < numExprs; i++) {
            std::string name = formatv("a{0:d}", i);
            X.push_back(c.int_const(name.c_str()));
        }
        for (int i = 0; i < numExprs; i++) {
            exprs[i] = cryptoutils->get_range(15);
        }
        for (int i = 0; i < 4; i++) {
            expr equ = c.int_val(0);
            for (int j = 0; j < numExprs; j++) {
                equ = equ + X[j] * truthTables[exprs[j]][i];
            }
            s.add(equ == 0);
        }
        expr notZeroCond = c.bool_val(false);
        // a1 != 0 || a2 != 0 || ... || an != 0
        for (int i = 0; i < numExprs; i++) {
            notZeroCond = notZeroCond || (X[i] != 0);
        }
        s.add(notZeroCond);
        if (s.check() != sat) {
            continue;
        }
        model m = s.get_model();
        for (int i = 0; i < numExprs; i++) {
            coeffs[exprs[i]] += m.eval(X[i]).as_int64();
        }
        delete[] exprs;
#ifdef USE_CACHE
        int64_t *coeffs_copy = new int64_t[15];
        std::copy(coeffs, coeffs + 15, coeffs_copy);
        cached_coeffs.push(coeffs_copy);
#endif
        return coeffs;
    }
}

Value *MBAUtils::insertLinearMBA(int64_t *coeffs, Instruction *insertBefore) {
    IRBuilder<> builder(insertBefore->getContext());
    builder.SetInsertPoint(insertBefore);
    Value *x, *y;
    if (isa<BinaryOperator>(insertBefore) && insertBefore->getNumOperands() == 2) {
        x = insertBefore->getOperand(0);
        y = insertBefore->getOperand(1);
    } else {
        Module &M = *insertBefore->getModule();
        Type *type = insertBefore->getOperand(0)->getType();
        uint64_t randX = cryptoutils->get_uint64_t(), randY = cryptoutils->get_uint64_t();
        GlobalVariable *xPtr =
            new GlobalVariable(M, type, false, GlobalValue::PrivateLinkage, ConstantInt::get(type, randX), "x");
        GlobalVariable *yPtr =
            new GlobalVariable(M, type, false, GlobalValue::PrivateLinkage, ConstantInt::get(type, randY), "y");
        x = builder.CreateLoad(type, xPtr);
        y = builder.CreateLoad(type, yPtr);
    }
    // Value *mbaExpr = builder.CreateAlloca(x->getType());
    // builder.CreateStore(ConstantInt::get(x->getType(), 0), mbaExpr);
    // mbaExpr = builder.CreateLoad(mbaExpr);
    Value *mbaExpr = ConstantInt::get(x->getType(), 0);
    Value *boolExpr, *term;
    for (int i = 0; i < 15; i++) {
        if (!coeffs[i])
            continue;
        // x & y
        if (i == 0)
            boolExpr = builder.CreateAnd(x, y);
        // x & ~y
        else if (i == 1)
            boolExpr = builder.CreateAnd(x, builder.CreateNot(y));
        // x
        else if (i == 2)
            boolExpr = x;
        // ~x & y
        else if (i == 3)
            boolExpr = builder.CreateAnd(builder.CreateNot(x), y);
        // y
        else if (i == 4)
            boolExpr = y;
        // x ^ y
        else if (i == 5)
            boolExpr = builder.CreateXor(x, y);
        // x | y
        else if (i == 6)
            boolExpr = builder.CreateOr(x, y);
        // ~(x | y)
        else if (i == 7)
            boolExpr = builder.CreateNot(builder.CreateOr(x, y));
        // ~(x ^ y)
        else if (i == 8)
            boolExpr = builder.CreateNot(builder.CreateXor(x, y));
        // ~y
        else if (i == 9)
            boolExpr = builder.CreateNot(y);
        // x | ~y
        else if (i == 10)
            boolExpr = builder.CreateOr(x, builder.CreateNot(y));
        // ~x
        else if (i == 11)
            boolExpr = builder.CreateNot(x);
        // ~x | y
        else if (i == 12)
            boolExpr = builder.CreateOr(builder.CreateNot(x), y);
        // ~(x & y)
        else if (i == 13)
            boolExpr = builder.CreateNot(builder.CreateAnd(x, y));
        // -1
        else if (i == 14)
            boolExpr = ConstantInt::get(x->getType(), -1);
        term = builder.CreateMul(ConstantInt::get(x->getType(), coeffs[i]), boolExpr);
        mbaExpr = builder.CreateAdd(mbaExpr, term);
    }
    return mbaExpr;
}

// Extended Euclid's Theorem function.
uint64_t exgcd(uint64_t a, uint64_t b, uint64_t &x, uint64_t &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    uint64_t g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

uint64_t inv(uint64_t a, uint64_t p) {
    uint64_t x, y;
    exgcd(a, p, x, y);
    // get the inverse element
    return (x % p + p) % p;
}

uint64_t inverse(uint64_t n, uint32_t bitWidth) {
    assert(bitWidth <= 32);
    return inv(n, 1LL << bitWidth);
}

void generateUnivariatePoly(uint64_t *a, uint64_t *b, uint32_t bitWidth) {
    uint64_t a0, a1, b0, b1, a1_inv;
    a0 = cryptoutils->get_uint64_t(), a1 = cryptoutils->get_uint64_t() | 1;

    // Calculate a1_inv
    a1_inv = inverse(a1, bitWidth);

    // Calculate b1
    b1 = a1_inv;

    // Calculate b0
    b0 = -(b1 * a0);

    a[0] = a0, a[1] = a1, b[0] = b0, b[1] = b1;
}

Value *MBAUtils::insertPolynomialMBA(Value *linearMBAExpr, Instruction *insertBefore) {
    IRBuilder<> builder(insertBefore->getContext());
    builder.SetInsertPoint(insertBefore);
    Type *operandType = insertBefore->getOperand(0)->getType();
    uint32_t bitWidth = operandType->getIntegerBitWidth();
    uint64_t a[2], b[2];
    generateUnivariatePoly(a, b, bitWidth);
    Value *expr;
    expr = builder.CreateMul(ConstantInt::get(operandType, b[1]), linearMBAExpr);
    expr = builder.CreateAdd(expr, ConstantInt::get(operandType, b[0]));
    expr = builder.CreateMul(ConstantInt::get(operandType, a[1]), expr);
    expr = builder.CreateAdd(expr, ConstantInt::get(operandType, a[0]));
    return expr;
}