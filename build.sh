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

tests_build_dir=`pwd`/tests/build
mkdir -p $tests_build_dir

cmake -G Ninja -S tests -B $tests_build_dir \
      -DCMAKE_C_COMPILER=$install_prefix/bin/clang \
      -DCMAKE_CXX_COMPILER=$install_prefix/bin/clang++

ninja -C $tests_build_dir

ctest --test-dir tests/build