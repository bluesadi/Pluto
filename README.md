# Pluto-Obfuscator
[English Documentation](README.md) | [中文文档](README_zh-cn.md)

Pluto-Obfuscator is a code obfuscator compatible with LLVM 12.0.1, LLVM 14.0.6, (more in the future...). Briefly speaking, Pluto-Obfuscator converts the source code into a functionally equivalent but much less understandable version at compile-time, protecting your software from reverse engineering.

## Installation
Download source code:
```
$ git clone https://github.com/bluesadi/Pluto-Obfuscator.git
```
### Dependencies
Install z3 (required by MbaObfuscation):
```
$ wget https://github.com/Z3Prover/z3/archive/refs/tags/z3-4.12.2.zip
$ tar xvf z3-4.12.2.zip
$ cd z3-z3-4.12.2
$ ./configure
$ cd build
$ make install
```
### Ubuntu/Windows (Ninja)
Install Ninja:
```
$ sudo apt install ninja-build
```
Build LLVM 12.0.1:
```
$ mkdir -p build/llvm-12.0.1
$ cd build/llvm-12.0.1
$ cmake -G "Ninja" -DCMAKE_INSTALL_PREFIX="../../install/llvm-12.0.1" ../../src/llvm-12.0.1
$ ninja install
```
Build LLVM 14.0.6:
```
$ mkdir -p build/llvm-14.0.6
$ cd build/llvm-14.0.6
$ cmake -G "Ninja" -DCMAKE_INSTALL_PREFIX="../../install/llvm-14.0.6" ../../src/llvm-14.0.6
$ ninja install
```