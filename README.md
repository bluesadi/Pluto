# Pluto-Obfuscator
[English Documentation](README.md) | [中文文档](README_zh-cn.md)

Pluto-Obfuscator is a code obfuscator compatible with LLVM 12.0.1, (more in the future...). Briefly speaking, Pluto-Obfuscator converts the source code into a functionally equivalent but much less understandable version at compile-time, protecting your software from reverse engineering.

## Installation
```
$ sudo apt install ninja-build
$ git clone https://github.com/bluesadi/Pluto-Obfuscator.git
$ cd Pluto-Obfuscator/llvm-12.0.1
$ mkdir -p build
$ cd build
$ cmake -G "Ninja" -DLLVM_ENABLE_PROJECTS="clang" \
        -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ \
        -DCMAKE_BUILD_TYPE=Release -DLLVM_TARGETS_TO_BUILD="X86" \
        -DBUILD_SHARED_LIBS=On -DCMAKE_INSTALL_PREFIX="../install" ../llvm
$ ninja -j16
$ ninja install
```