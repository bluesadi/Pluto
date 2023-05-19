cmake_minimum_required(VERSION 3.20)
project(Pluto-Obfuscator)

set(LLVM_ENABLE_PROJECTS "clang")
set(LLVM_TARGETS_TO_BUILD "X86")
set(LLVM_INCLUDE_BENCHMARKS FALSE)
set(BUILD_SHARED_LIBS "On")
set(CMAKE_BUILD_TYPE "Release")
add_subdirectory(llvm)