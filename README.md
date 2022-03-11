# Pluto-Obfuscator
Pluto is an obfuscator based on LLVM 12.0.1, being developed and maintained by 34r7h4mn.
> Pluto is a dwarf planet in the Kuiper belt, a ring of bodies beyond the orbit of Neptune.
## Environment
- Ubuntu 20.04.3 LTS
- Clang/LLVM 12.0.1
- CMake 3.16.3
- Ninja 1.10.0
- libz3-dev 4.8.7-4build1
## Usage
### Dependencies
The MBA Obfuscation pass depends on z3-solver. On Ubuntu, you can simply install it with the following command:
```shell
sudo apt install libz3-dev 
```
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



### Examples

Several examples are available in [obfu-examples](obfu-examples) and [run-examples.sh](run-examples.sh)
## Features
- Control Flow Flattening
- Bogus Control Flow
- Instruction Substitution
- Random Control Flow
- Variable Substitution
- String Encryption
- Globals Encryption
- [Trap Angr](TrapAngr.md)
- MBA Obfuscation