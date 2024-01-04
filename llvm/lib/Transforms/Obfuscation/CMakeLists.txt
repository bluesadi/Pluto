add_llvm_component_library(LLVMObfuscation
  HelloWorld.cpp
  CryptoUtils.cpp
  Flattening.cpp
  MBAUtils.cpp
  MBAObfuscation.cpp
  Substitution.cpp
  IndirectCall.cpp
  BogusControlFlow.cpp
  GlobalEncryption.cpp
  Pipeline.cpp

  LINK_COMPONENTS
  Core
  Support
  Analysis
  TransformUtils
  
  LINK_LIBS
  z3
  )
