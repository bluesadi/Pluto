# Pluto-Obfuscator
Pluto-Obfuscator is a code obfuscator based on LLVM 12.0.1 and its LLVM Pass framework. Briefly speaking, Pluto-Obfuscator converts the source code into a functionally equivalent but much less understandable version at compile-time, protecting your software from reverse engineering.
> The documentation of Pluto-Obfuscator is still lacking. I will work on it when I am available.

## Features
Pluto-Obfuscator implements multiple algorithms for obfuscation. The first three bold ones are the most recommended as they are relatively stabler and more effective compared to the other:

|  Name  | Identifier |  Documentation | Authors |
|  ----  | ----  | ---- | ---- |
| **Control Flow Flattening Enhanced** | fla-ex | - English Documentation<br>- [Chinese Blog](https://bbs.pediy.com/thread-274778.htm) | [@za233](https://github.com/za233) |
| **Globals Encryption** | gle | None | [@34r7hm4n](https://github.com/bluesadi) |
| **MBA Obfuscation** | mba | - English Documentation<br>- [Chinese Blog](https://bbs.pediy.com/thread-271574.htm) | [@34r7hm4n](https://github.com/bluesadi) |
| Control Flow Flattening| fla | [Ref: obfuscator-llvm/obfuscator](https://github.com/obfuscator-llvm/obfuscator/wiki/Control-Flow-Flattening) | [@34r7hm4n](https://github.com/bluesadi) |
| Bogus Control Flow | bcf | [Ref: obfuscator-llvm/obfuscator](https://github.com/obfuscator-llvm/obfuscator/wiki/Bogus-Control-Flow) | [@34r7hm4n](https://github.com/bluesadi) |
| Instruction Substitution | sub | [Ref: obfuscator-llvm/obfuscator](https://github.com/obfuscator-llvm/obfuscator/wiki/) | [@34r7hm4n](https://github.com/bluesadi) |
| Random Control Flow | rcf | None | [@34r7hm4n](https://github.com/bluesadi) |
| Variable Substitution | vsb | None | [@34r7hm4n](https://github.com/bluesadi) |
| Trap Angr | trap-angr | [English Documentation](docs/TrapAngr.md) | [@34r7hm4n](https://github.com/bluesadi) |

## Installation
The first step is always to clone this repository:
```
$ git clone https://github.com/bluesadi/Pluto-Obfuscator.git
$ cd Pluto-Obfuscator
```

No matter which OS you are using, make sure you include all the following commands in the PATH environment variable:
```
gcc g++ cmake ninja
```

If you are using Ubuntu, you may install all the required packages by:
```shell
$ sudo apt install gcc g++ cmake ninja-build
```

The final step is to execute `./build.sh`, which is a shell script that automatically compiles this project and install it in the [/install](/install) directory. Such script for MacOS are also available at [build_macos.sh](build_macos.sh). As of Windows, you may execute `./build.sh` on Git Bash (you must have installed it if you get this project by `git clone`). By default the script utilizes all CPU cores of your machine to compile as fast as possible. If you don't want the compilation occupies all the CPU cores, making your computer laggy, you may specify the maximum cores you want to allocate. Let's say your computer has 16 CPU cores, you can use `./build.sh 12` to tell the script only to use 8 cores for compilation.

**TROUBLE SHOOTING:** LLVM is a rather large project, please allocate enough memory (at least 8GB) for your virtual machine or WSL during compilation, otherwise you will probably encounter an error message `g++: fatal error: Killed signal terminated program cc1plus` caused by insufficient memory.

## Usage

```shell
$ ./install/clang[++] [-mllvm <identifier>] [-mllvm <another option>] <source files> [-o <output file>]
```

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
