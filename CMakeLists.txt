cmake_minimum_required(VERSION 3.20)
project(Pluto)

set(LLVM_ENABLE_PROJECTS "clang;lld")
set(LLVM_TARGETS_TO_BUILD "X86")
set(LLVM_ENABLE_LLD ON)
set(LLVM_INCLUDE_BENCHMARKS OFF)
add_subdirectory(llvm)