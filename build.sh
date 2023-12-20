#!/bin/sh

build_dir=`pwd`/build
install_prefix=`pwd`/install
mkdir -p $build_dir
mkdir -p $install_prefix

cmake -G Ninja -S llvm -B $build_dir \
      -DLLVM_ENABLE_PROJECTS="clang" \
      -DLLVM_INCLUDE_BENCHMARKS=OFF \
      -DCMAKE_INSTALL_PREFIX=$install_prefix \
      -DCMAKE_C_COMPILER=gcc \
      -DCMAKE_CXX_COMPILER=g++ \
      -DCMAKE_BUILD_TYPE=Release

ninja -C $build_dir install