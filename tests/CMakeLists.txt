cmake_minimum_required(VERSION 3.20)
project(tests)
include(CTest)

add_compile_options(-mllvm -passes=hlw)

add_executable(test-aes tiny-AES-c/test.c tiny-AES-c/aes.c tiny-AES-c/aes.h)
add_test(NAME test-aes
         COMMAND test-aes)