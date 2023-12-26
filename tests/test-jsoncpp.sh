CXX=`pwd`/install/bin/clang++
CXX_FLAGS="-mllvm -passes=hlw,idc,mba,fla,sub"

cd tests/jsoncpp
rm -rf build
mkdir -p build
cmake -B build \
      -DCMAKE_CXX_COMPILER=$CXX \
      -DCMAKE_CXX_FLAGS="$CXX_FLAGS"
make -j`nproc` -C build