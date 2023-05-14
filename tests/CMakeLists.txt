include(CTest)

set(CMAKE_C_COMPILER "../llvm-12.0.1/install/bin/clang")
set(CMAKE_CXX_COMPILER "../llvm-12.0.1/install/bin/clang++")
add_compile_options(-mllvm -enable-fla -fno-legacy-pass-manager)

add_executable(test-aes tiny-AES-c/test.cpp tiny-AES-c/aes.c tiny-AES-c/aes.h tiny-AES-c/aes.hpp)
add_test(NAME test-aes
         COMMAND test-aes)