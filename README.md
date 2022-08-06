# Pluto-Obfuscator
Pluto is an obfuscator based on LLVM 12.0.1, mainly developed by 34r7h4mn.
> Pluto is a dwarf planet in the Kuiper belt, a ring of bodies beyond the orbit of Neptune.

## Environment
This project was developed and tested on the following environment:
- Ubuntu 20.04.3 LTS
- Clang/LLVM 12.0.1
- CMake 3.16.3
- Ninja 1.10.0

You can also build this project on Windows and MacOS, or even merge it into Android NDK toolchain (tested on Android NDK r23).

## Features
- Control Flow Flattening
- Bogus Control Flow
- Instruction Substitution
- Random Control Flow
- Variable Substitution
- String Encryption
- Globals Encryption
- [Trap Angr (Experimental)](TrapAngr.md)
- MBA Obfuscation

## Usage
### Building on Linux/Windows
The following commands work on both Linux and Windows:
```shell
cd build
cmake -G "Ninja" -DLLVM_ENABLE_PROJECTS="clang" \
    -DCMAKE_BUILD_TYPE=Release -DLLVM_TARGETS_TO_BUILD="X86" \
    -DBUILD_SHARED_LIBS=On ../llvm
ninja
```
### Building on MacOS

```shell
mkdir -p build
cd build
cmake -G "Ninja" -DLLVM_ENABLE_PROJECTS="clang" \
    -DCMAKE_BUILD_TYPE=Release \
    -DDEFAULT_SYSROOT=$(xcrun --show-sdk-path) \
    -DCMAKE_OSX_SYSROOT=/Library/Developer/CommandLineTools/SDKs/MacOSX11.3.sdk \
    -DCMAKE_OSX_ARCHITECTURES="arm64;x86_64" \
    ../llvm
ninja
```



## Test
### Fast test on AES
Run a test case of AES to check out buggy code quickly and roughly.

See [fast-check.sh](fast-check.sh) and [test/aes](test/aes/).
### Full test on libsecp256k1
We have a full test on a crypto library named libsecp256k1 from [bitcoin-core/secp256k1](https://github.com/bitcoin-core/secp256k1), to insure our passes work fine in most cases.

Passed:
- Flattening: `-O2 -mllvm -fla`
- BogusControlFlow: `-O2 -mllvm -bcf`
- Substitution: `-O2 -mllvm -sub`
- GlobalsEncryption: `-O2 -mllvm -gle`
- MBAObfuscation: `-O2 -mllvm -mba -mllvm -mba-prob=100`
- FullProtection (**HIGHLY RECOMMENDED**): `-mllvm -mba -mllvm -mba-prob=100 -mllvm -fla -mllvm -gle`

See [check.sh](check.sh) and [test/secp256k1](test/secp256k1/).
