add_llvm_component_library(LLVMObfuscation
  HelloWorld.cpp
  SplitBasicBlock.cpp
  CryptoUtils.cpp
  Utils.cpp
  Flattening.cpp
  BogusControlFlow.cpp
  Substitution.cpp
  GlobalsEncryption.cpp
  VariableSubstitution.cpp

  DEPENDS
  intrinsics_gen

  LINK_COMPONENTS
  Core
  Support
  Analysis
  TransformUtils
  
  )
