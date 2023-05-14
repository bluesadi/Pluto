include(CTest)

add_subdirectory(tiny-AES-c)

set(CMAKE_CXX_COMPILER "../llvm-12.0.1/install/bin/clang++")
add_compile_options(-mllvm -enable-fla -fno-legacy-pass-manager)

add_executable(test-aes tiny-AES-c/test.cpp)
target_link_libraries(test-aes tiny-aes)
add_test(NAME test-aes
         COMMAND test-aes)