../install/bin/clang -O0 example.c -o example
../install/bin/clang -O0 -mllvm -passes=bcf example.c -o example.obfu

../install/bin/clang -O0 hello.c -o hello
../install/bin/clang -O0 -mllvm -passes=bcf hello.c -o hello.obfu