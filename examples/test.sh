../install/bin/clang -O0 example.c -o example
../install/bin/clang -O0 -mllvm -passes=bcf example.c -o example.obfu