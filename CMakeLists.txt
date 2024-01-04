cmake_minimum_required(VERSION 3.20)
project(Pluto)

set(LLVM_ENABLE_PROJECTS "clang;lld" CACHE STRING "")
set(LLVM_TARGETS_TO_BUILD "X86" CACHE STRING "")
set(LLVM_INCLUDE_BENCHMARKS OFF CACHE BOOL "")
add_subdirectory(llvm)