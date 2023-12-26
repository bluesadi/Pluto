CXX=`pwd`/install/bin/clang++
CXX_FLAGS="-mllvm -passes=hlw,fla,sub,mba"

cd tests/json
rm -rf build
mkdir -p build
cmake -B build \
      -G "Ninja" \
      -DCMAKE_CXX_COMPILER=$CXX \
      -DCMAKE_CXX_FLAGS="$CXX_FLAGS"
ninja -j`nproc` -C build
ninja -C build test