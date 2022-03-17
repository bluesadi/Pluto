export CXX=`which clang++`
export CFLAGS="-mllvm -hlw"
if [ -z $CXX ]; then
    echo "Cannot find clang path. Please specify it manually."
    exit 1
fi

cd test/aes
rm -f TestProgram.out
$CXX AES.cpp TestProgram.cpp $CFLAGS -o TestProgram.out
./TestProgram.out flag{s1mpl3_11vm_d3m0} 