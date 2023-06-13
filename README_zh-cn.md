# Pluto-Obfuscator
[English Documentation](README.md) | [中文文档](README_zh-cn.md)

Pluto-Obfuscator是一款兼容LLVM 12.0.1的代码混淆器。简单来说, Pluto-Obfuscator能够在编译时将源代码转换为一种功能上等价，但更难以被理解的混淆代码，增加逆向工程的难度。

## 安装方法
下载源代码：
```
$ git clone https://github.com/bluesadi/Pluto-Obfuscator.git
```
### 依赖
安装z3（MbaObfuscation的依赖库）：
```
$ wget https://github.com/Z3Prover/z3/archive/refs/tags/z3-4.12.2.zip
$ tar xvf z3-4.12.2.zip
$ cd z3-z3-4.12.2
$ ./configure
$ cd build
$ make install
```
### Ubuntu/Windows (Ninja)
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