include_directories(include)

add_llvm_component_library(LLVMObfuscation
  CryptoUtils.cpp
  Utils.cpp
  HelloWorld.cpp
  Flattening.cpp
  MbaUtils.cpp
  MbaObfuscation.cpp

  LINK_COMPONENTS
  Core
  Support
  Analysis
  TransformUtils

  LINK_LIBS
  z3
  )