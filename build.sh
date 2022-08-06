mkdir -p build
cd build
make uninstall
cmake -G "Ninja" -DLLVM_ENABLE_PROJECTS="clang" \
    -DCMAKE_BUILD_TYPE=Release -DLLVM_TARGETS_TO_BUILD="X86" \
    -DBUILD_SHARED_LIBS=On ../llvm
ninja -j 8
ninja install # Comment it out if you already have another version of LLVM installed on your machine