add_llvm_component_library(LLVMObfuscation
  HelloWorld.cpp

  LINK_COMPONENTS
  Core
  Support
  Analysis
  TransformUtils
  )