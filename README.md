# Pluto-Obfuscator
Pluto-Obfuscator is a code obfuscator based on LLVM 12.0.1 and its LLVM Pass framework. Briefly speaking, Pluto-Obfuscator converts the source code into a functionally equivalent but much less understandable version at compile-time, protecting your software from reverse engineering.
> 34r7hm4n: The documentation of this project is still lacking. I will work on it when I am available.

## Features
Pluto-Obfuscator implements multiple algorithms for obfuscation. The first three bold ones are the most recommended as they are relatively stabler and more efficient compared to the other:

|  Name  | Identifier | Documents | Authors |
|  ----  | ----  | ---- | ---- |
| **Control Flow Flattening Enhanced** | fla-ex | [Chinese Document](https://bbs.pediy.com/thread-274778.htm) | [@za233](https://github.com/za233) |
| **Globals Encryption** | gle | - | [@34r7hm4n](https://github.com/bluesadi) |
| **MBA Obfuscation** | mba | [Chinese Document](https://bbs.pediy.com/thread-271574.htm) | [@34r7hm4n](https://github.com/bluesadi) |
| Control Flow Flattening| fla | [Ref: OLLVM](https://github.com/obfuscator-llvm/obfuscator/wiki/Control-Flow-Flattening) | [@34r7hm4n](https://github.com/bluesadi) |
| Bogus Control Flow | bcf | [Ref: OLLVM](https://github.com/obfuscator-llvm/obfuscator/wiki/Bogus-Control-Flow) | [@34r7hm4n](https://github.com/bluesadi) |
| Instruction Substitution | sub | [Ref: OLLVM](https://github.com/obfuscator-llvm/obfuscator/wiki/) | [@34r7hm4n](https://github.com/bluesadi) |
- Random Control Flow
- Variable Substitution
- String Encryption
- [Trap Angr (MORE OF A TOY)](docs/TrapAngr.md)

## Installation
No matter what OS you are using, first make sure you include all the following commands in the PATH environment variable:
```
gcc g++ cmake make ninja
```

I compiled this project on Ubuntu 20.04 (WSL2), so I would assume you are also using Ubuntu for the next steps.

You may install all the required packages using:
```shell
$ sudo apt install gcc g++ cmake make ninja-build
```

The final step is to execute `./build.sh`, which is a shell script that automatically compiles this project and install it in the [/install](/install) directory. Such scripts for MacOS and Windows are also available at [build_macos.sh](build_macos.sh) and [build_win.bat](build_win.bat). Please feel free to use them!

## Usage



### Filter Mode
In case you just want to obfuscate specific functions, Pluto-Obfuscator also provides a filter mechanism using annotation, to help you specify which functions should or should not be obfuscated.

To enable this mechanism, you should pass `-mllvm -filter-mode=include` or `-mllvm -filter-mode=exclude` to clang as an argument. 

- `-filter-mode=include`: only those functions with "include" annotation will be obfuscated.
- `-filter-mode=exclude`: ignore those functions with "exclude" annotation.
- `-filter-mode=none`: all functions will be processed. (by defualt)

For example:
```shell
clang++ TestFilter.cpp -mllvm -fla -mllvm -filter-mode=include -o TestFilter_include    # include mode
clang++ TestFilter.cpp -mllvm -fla -mllvm -filter-mode=exclude -o TestFilter_include    # exclude mode
clang++ TestFilter.cpp -mllvm -fla -mllvm -o TestFilter_include    # default mode
```

Following is a self-explanatory snippet showing how to annonate functions. In this case, only foo1 will be obfuscated in `include` mode. Only foo2 will be ignored in `exclude` mode. And foo3 will always be obfuscated:
```cpp
#define FUNC_INCLUDE __attribute__((annotate("include")))
#define FUNC_EXCLUDE __attribute__((annotate("exclude")))

FUNC_INCLUDE
void foo1(){ }

FUNC_EXCLUDE
void foo2(){ }

void foo3(){ }

int main(){
    foo1();
    foo2();
    foo3();
}
```

## Test suite
**IMPORTANT:** If you would like to improve this project by creating pull requests, please make sure your modified code can pass the tests as follows. Issues and pull requests about the most recommended passes will be prioritized.

### Quick Test on AES
Usage: `./fast-check [your-passes]` (e.g., `./fast-check.sh mba mba-prob=50 fla-ex gle`).

See [fast-check.sh](fast-check.sh) and [test/aes](test/aes/).

### Test on libsecp256k1
Usage: `./check.sh [your-passes]` (e.g., `./check.sh mba mba-prob=50 fla-ex gle`)

Generally, it will cost several minutes to be done, much slower compared to AES test.

Passed Parameters:
- Flattening: `fla`
- FlatteningEnhanced: `fla-ex`
- Substitution: `sub`
- GlobalsEncryption: `gle`
- MBAObfuscation: `mba mba-prob=100`
- FullProtection (**HIGHLY RECOMMENDED**): `mba mba-prob=50 fla-ex gle`

See [check.sh](check.sh) and [test/secp256k1](test/secp256k1/).
