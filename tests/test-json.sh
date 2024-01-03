CXX=`pwd`/install/bin/clang++
CXX_FLAGS="-O0 -flto -fuse-ld=lld -mllvm -passes=mba,sub,fla,gle -Xlinker -mllvm -Xlinker -passes=idc -Wno-unused-command-line-argument"

cd tests/json
rm -rf build
mkdir -p build
cmake -B build \
      -G "Ninja" \
      -DCMAKE_CXX_COMPILER=$CXX \
      -DCMAKE_CXX_FLAGS="$CXX_FLAGS"
ninja -j`nproc` -C build
ctest --test-dir build --output-on-failure