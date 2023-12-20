# Pluto
[English Documentation](README.md) | [中文文档](README_zh-cn.md)

Pluto is a code obfuscator built on top of LLVM 14.0.6 (more in the future...). In summary, Pluto converts the source code into a functionally equivalent but much more complicated form at compile-time, protecting your software from being cracked.

## Installation
Download source code:
```
$ git clone https://github.com/bluesadi/Pluto.git
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
### Ubuntu
Install Ninja and other dependencies:
```
$ sudo apt install ninja-build cmake python3 gcc g++
```
Build and install to `./install` directory:
```
$ make
```