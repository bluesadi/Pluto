CXX=`pwd`/install/bin/clang++
CXX_FLAGS="-flto -fuse-ld=lld -O3 -mllvm -passes=mba,sub,fla -Xlinker -mllvm -Xlinker -passes=hlw,idc -Wno-unused-command-line-argument"

cd tests/json
rm -rf build
mkdir -p build
cmake -B build \
      -G "Ninja" \
      -DCMAKE_CXX_COMPILER=$CXX \
      -DCMAKE_CXX_FLAGS="$CXX_FLAGS"
ninja -j`nproc` -C build
ctest --test-dir build --output-on-failure