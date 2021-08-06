# OLLVM++
Obfuscator refactored and extended from OLLVM.
## Environment
- Ubuntu 18.04.5 LTS
- LLVM 12.0.1
- Clang 12.0.1
- CMake 3.21.1
## Features
- Control Flow Flattening
- Bogus Control Flow
- Instruction Substitution
- Random Control Flow
- Constant Substitution
## Project Structure
- `Build` Output directory
- `Test` Test programs
  - `Bin` Binary file generated from test programs
  - `IR` LLVM IR generated from test programs
- `Transforms`
  - `include` Header files of obfuscating passes
  - `src` Source files of obfuscating passes
- `.gitignore`
- `README.md`
- `test.sh`