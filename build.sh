mkdir -p build
cmake -G Ninja -S llvm -B build \
      -DLLVM_ENABLE_PROJECTS="clang;lld" \
      -DLLVM_TARGETS_TO_BUILD="X86" \
      -DLLVM_ENABLE_LLD=ON \
      -DLLVM_INCLUDE_BENCHMARKS=OFF \
      -DCMAKE_C_COMPILER="gcc" \
      -DCMAKE_CXX_COMPILER="g++" \
      -DCMAKE_INSTALL_PREFIX="install" \
      -DCMAKE_BUILD_TYPE=Release
ninja -j`nproc` -C build install