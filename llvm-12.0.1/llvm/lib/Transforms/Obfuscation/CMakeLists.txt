include_directories(include)


add_llvm_component_library(LLVMObfuscation
  CryptoUtils.cpp
  Utils.cpp
  HelloWorld.cpp
  Flattening.cpp

  LINK_COMPONENTS
  Core
  Support
  Analysis
  TransformUtils
  )