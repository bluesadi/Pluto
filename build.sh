processors=$1
if [ -z $processors ]; then
    if [ "$(uname)" == "Darwin" ]; then
        processors=$(sysctl -n hw.physicalcpu)
    else
        processors=$(nproc)
    fi
fi

mkdir -p build
cd build

if [ "$(uname)" == "Darwin" ]; then
    cmake -G "Ninja" -DLLVM_ENABLE_PROJECTS="clang" \
	-DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ \
        -DCMAKE_BUILD_TYPE=Release \
        -DDEFAULT_SYSROOT=$(xcrun --show-sdk-path) \
        -DCMAKE_OSX_SYSROOT=/Library/Developer/CommandLineTools/SDKs/MacOSX$(xcrun --show-sdk-version).sdk \
        -DCMAKE_OSX_ARCHITECTURES="arm64;x86_64" \
        -DCMAKE_INSTALL_PREFIX="../install" \
        ../llvm
else   
    cmake -G "Ninja" -DLLVM_ENABLE_PROJECTS="clang" \
	-DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ \
        -DCMAKE_BUILD_TYPE=Release -DLLVM_TARGETS_TO_BUILD="X86" \
        -DBUILD_SHARED_LIBS=On -DCMAKE_INSTALL_PREFIX="../install" ../llvm
fi

echo "-- Building on $(uname)"
echo "-- Building with $processors CPU cores"

ninja -j$processors
ninja install
