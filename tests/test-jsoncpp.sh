CXX="`pwd`/install/bin/clang++"
CXX_FLAGS="-flto -fuse-ld=lld -O3 -mllvm -passes=mba,fla,sub -Xlinker -mllvm -Xlinker -passes=hlw,idc -Wno-unused-command-line-argument"

cd tests/jsoncpp
rm -rf build
mkdir -p build
cmake -B build \
      -DCMAKE_CXX_COMPILER=$CXX \
      -DCMAKE_CXX_FLAGS="$CXX_FLAGS" 
make -j`nproc` -C build