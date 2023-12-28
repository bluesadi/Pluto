# Pluto
[English Documentation](README.md) | [中文文档](README_zh-cn.md)

Pluto is a code obfuscator built on top of LLVM 14.0.6 (more in the future...). In summary, Pluto converts the source code into a functionally equivalent but much more complicated form at compile-time, protecting your software from being cracked.

## Installation
Download source code:
```
$ git clone https://github.com/bluesadi/Pluto.git
```
### Ubuntu
Install z3 (required by MbaObfuscation):
```
$ sudo apt install libz3-dev 
```
(Optional) Install lld:
```
// This is an optional depencency to speed up the linking stage when building LLVM.
// If you don't want to install this dependency, remove the line `set(LLVM_ENABLE_LLD ON)` in CMakeLists.txt
$ sudo apt install lld
```
Install Ninja and other dependencies:
```
$ sudo apt install ninja-build cmake python3 gcc g++
```
Build and install Pluto to the ./install directory:
```
$ ./build.sh
```