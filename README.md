# Pluto
[English](README.md) | [中文](README_zh-cn.md)

Pluto is a code obfuscator built on top of LLVM 14.0.6 (more in the future...). In summary, Pluto converts the source code into a functionally equivalent but much more complicated form at compile-time, protecting your software from being cracked.

## Installation
Download source code:
```
$ git clone https://github.com/bluesadi/Pluto.git
```
Switch to `hs-intern` branch:
```
$ git checkout hs-intern
```
### Ubuntu
Install z3 (required by MBAObfuscation):
```
$ sudo apt install libz3-dev 
```
Install Ninja and other dependencies:
```
$ sudo apt install ninja-build cmake python3 gcc g++
```
Build and install Pluto to `./install` directory:
```
$ cd Pluto
$ mkdir -p build
$ cmake -G Ninja -S . -B build \
        -DCMAKE_C_COMPILER="gcc" \
        -DCMAKE_CXX_COMPILER="g++" \
        -DCMAKE_INSTALL_PREFIX="install" \
        -DCMAKE_BUILD_TYPE=Release
$ ninja -j`nproc` -C build install
```

## Usage
// TODO