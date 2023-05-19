cmake_minimum_required(VERSION 3.20)
project(tests)
include(CTest)

add_compile_options(-mllvm -enable-mba -fno-legacy-pass-manager)

add_executable(test-aes tiny-AES-c/test.cpp tiny-AES-c/aes.c tiny-AES-c/aes.h tiny-AES-c/aes.hpp)
add_test(NAME test-aes
         COMMAND test-aes)