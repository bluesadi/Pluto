cmake_minimum_required(VERSION 3.20)
project(tests)
include(CTest)

# add_compile_options(-flto -fno-legacy-pass-manager)
# add_link_options(-flto -fuse-ld=gold -fno-legacy-pass-manager -Xlinker -mllvm -Xlinker -Wl,--plugin-opt=-enable-symobfu)
add_compile_options(-fno-legacy-pass-manager -mllvm -passes=icl)

add_executable(test-aes tiny-AES-c/test.c tiny-AES-c/aes.c tiny-AES-c/aes.h)
add_test(NAME test-aes
         COMMAND test-aes)