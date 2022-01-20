# OLLVM++
Obfuscator refactored and extended from OLLVM.
> 购买了看雪课程《LLVM与代码混淆技术》的小伙伴请注意，最新版本的OLLVM++与课程中的版本有所差别，要浏览与课程版本一致的OLLVM++源码[请点这里](https://github.com/bluesadi/OLLVM-plusplus/tree/kanxue)。
## Environment
- Ubuntu 18.04.5 LTS
- LLVM 12.0.1
- Clang 12.0.1
- CMake 3.21.1
## Usage
1. Build and install LLVM on your machine. See [Building LLVM with CMake](https://llvm.org/docs/CMake.html)
2. Then learn how to develop LLVM passes out of LLVM’s source tree. See [Developing LLVM passes out of source](https://llvm.org/docs/CMake.html#developing-llvm-passes-out-of-source)
3. There are some examples in [test.sh](test.sh)
## Features
- Control Flow Flattening
- Bogus Control Flow
- Instruction Substitution
- Random Control Flow
- Constant Substitution
- String Obfuscation
- Global Variable Obfuscation
