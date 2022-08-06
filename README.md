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
- [Trap Angr (Experimental)](docs/TrapAngr.md)
- MBA Obfuscation

## Usage
### Build on Linux/Windows
The following commands work on both Linux and Windows:
```shell
cd build
cmake -G "Ninja" -DLLVM_ENABLE_PROJECTS="clang" \
    -DCMAKE_BUILD_TYPE=Release -DLLVM_TARGETS_TO_BUILD="X86" \
    -DBUILD_SHARED_LIBS=On ../llvm
ninja
ninja install   # Comment it out if you already have another version of LLVM installed on your machine
```
### Build on MacOS

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
ninja install # Comment it out if you already have another version of LLVM installed on your machine
```

### Filter Mode
In case you just want to obfuscate specific functions, Pluto-Obfuscator also provides a filter mechanism using annotation, to help you specify which functions should or should not be obfuscated.

To enable this mechanism, you should add `-mllvm -filter-mode=include` or `-mllvm -filter-mode=include` to clang as an argument. 

- `-filter-mode=include`: only those functions with `include` annotation will be obfuscated.
- `-filter-mode=exclude`: those functions with `exclude` annotation will not be obfuscated. 
- `-filter-mode=none`: all functions will be processed. (defualt)

For example:
```shell
clang++ TestFilter.cpp -mllvm -fla -mllvm -filter-mode=include -o TestFilter.include
```

Following is a self-explanatory snippet showing how to annonate functions:
```cpp
#define FUNC_INCLUDE __attribute__((annotate("include")))
#define FUNC_EXCLUDE __attribute__((annotate("exclude")))

FUNC_INCLUDE
void foo1(){

}

FUNC_EXCLUDE
void foo2(){

}

void foo3(){

}

int main(){
    foo1();
    foo2();
    foo3();
}
```

## Test
### Quick Test on AES
If you want to develop your own passes on top of this project, you can simply execute this script to check whether your passes work well.

For example, `fast-check gle mba mba-prob=40`.

See [fast-check.sh](fast-check.sh) and [test/aes](test/aes/).
### Full Test on libsecp256k1
We have a full test on a crypto library named libsecp256k1 from [bitcoin-core/secp256k1](https://github.com/bitcoin-core/secp256k1), to insure our passes work fine in most cases.

Passed:
- Flattening: `-O2 -mllvm -fla`
- BogusControlFlow: `-O2 -mllvm -bcf`
- Substitution: `-O2 -mllvm -sub`
- GlobalsEncryption: `-O2 -mllvm -gle`
- MBAObfuscation: `-O2 -mllvm -mba -mllvm -mba-prob=100`
- FullProtection (**HIGHLY RECOMMENDED**): `-s -mllvm -mba -mllvm -mba-prob=100 -mllvm -fla -mllvm -gle`

See [check.sh](check.sh) and [test/secp256k1](test/secp256k1/).
