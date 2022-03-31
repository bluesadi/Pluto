add_subdirectory(z3)

add_llvm_component_library(LLVMObfuscation
  PassRegistry.cpp
  HelloWorld.cpp
  SplitBasicBlock.cpp
  CryptoUtils.cpp
  Utils.cpp
  Flattening.cpp
  FlatteningEnhanced.cpp
  BogusControlFlow.cpp
  Substitution.cpp
  GlobalsEncryption.cpp
  VariableSubstitution.cpp
  RandomControlFlow.cpp
  TrapAngr.cpp
  MBAObfuscation.cpp
  MBAUtils.cpp

  DEPENDS
  intrinsics_gen
  
  LINK_LIBS
  libz3

  LINK_COMPONENTS
  Core
  Support
  Analysis
  TransformUtils
  )