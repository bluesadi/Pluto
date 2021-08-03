# OLLVM++
## Tested Environment
- Ubuntu 18.04.5 LTS
- LLVM 12.0.1
- Clang 12.0.1
## Supported Obfuscations
- Control Flow Flattening
- Bogus Control Flow
- Instruction Substitution
## Folder Structure
- `Build` Build ouput
- `Test` Test program, generated IR and binary.
- `Transforms`
  - `include` Header files of obfuscator passes
  - `src` Source files of obfuscator passes
- `.gitignore`
- `README.md`
- `test.sh`