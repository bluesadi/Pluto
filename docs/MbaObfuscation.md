# MbaObfuscation
## Category
Data obfuscation
## Options
### -enable-mba
Enable MbaObfuscation
## Relevant Code
- [MbaUtils.cpp](src/llvm-12.0.1/llvm/lib/Transforms/Obfuscation/MbaUtils.cpp)
- [MbaObfuscation.cpp](src/llvm-12.0.1/llvm/lib/Transforms/Obfuscation/MbaObfuscation.h)
## Description
**Some of following statements might be not correct. Please submit an issue if you find any mistake.**

MBA (Mixed Boolean-Arithmetic) obfuscation was first proposed by Zhou et al. in [*Information Hiding in Software with Mixed Boolean-Arithmetic Transforms*](https://link.springer.com/chapter/10.1007/978-3-540-77535-5_5). It's a practical method to transform simple mathematical expressions into complicated mixed boolean-arithemtic expressions, namely, expressions consisting of both boolean expressions and arithemtic expressions, thus hindering reverse engineers and SMT solvers. For example, `x + y` can be transformed into `(x ⊕ y) − ((−2x − 1) ∨ (−2y − 1)) − 1` which is much more difficult to understand.

MbaObfuscation is twofold. The first part is linear MbaObfuscation, which has been defeated by a USENIX paper [*MBA-Blast: Unveiling and Simplifying Mixed Boolean-Arithmetic Obfuscation*](https://www.usenix.org/conference/usenixsecurity21/presentation/liu-binbin). The second part is polynomial MbaObfuscation, which is based on the linear MbaObfuscation. To the best of my knowledge, polynomial MbaObfuscation is still unresolved. So it's a safe obfuscation method for now.

// TODO explain more