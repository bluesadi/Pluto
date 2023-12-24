CXX=`pwd`/install/bin/clang++
CXX_FLAGS="-mllvm -passes=hlw,fla"

cd tests/jsoncpp
rm -rf build
mkdir -p build
cmake -B build \
      -DCMAKE_CXX_COMPILER=$CXX \
      -DCMAKE_CXX_FLAGS="$CXX_FLAGS"
make -C build