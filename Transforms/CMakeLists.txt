project(OLLVM++)
cmake_minimum_required(VERSION 3.20)
find_package(LLVM REQUIRED CONFIG)

list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(AddLLVM)
include_directories("./include")

separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})
include_directories(${LLVM_INCLUDE_DIRS})
#link_libraries("libLLVMTransformUtils.so")
add_llvm_library( LLVMObfuscator MODULE
  src/HelloWorld.cpp
  src/Flattening.cpp
  src/BogusControlFlow.cpp
  src/Substitution.cpp
  src/RandomControlFlow.cpp
  src/ConstantSubstitution.cpp
  src/SplitBasicBlock.cpp
  src/Utils.cpp
)