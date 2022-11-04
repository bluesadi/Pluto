# This file allows users to call find_package(Clang) and pick up our targets.


# Compute the installation prefix from this LLVMConfig.cmake file location.
get_filename_component(CLANG_INSTALL_PREFIX "${CMAKE_CURRENT_LIST_FILE}" PATH)
get_filename_component(CLANG_INSTALL_PREFIX "${CLANG_INSTALL_PREFIX}" PATH)
get_filename_component(CLANG_INSTALL_PREFIX "${CLANG_INSTALL_PREFIX}" PATH)
get_filename_component(CLANG_INSTALL_PREFIX "${CLANG_INSTALL_PREFIX}" PATH)

find_package(LLVM REQUIRED CONFIG
             HINTS "${CLANG_INSTALL_PREFIX}/lib/cmake/llvm")

set(CLANG_EXPORTED_TARGETS "clangBasic;clangAPINotes;clangLex;clangParse;clangAST;clangDynamicASTMatchers;clangASTMatchers;clangCrossTU;clangSema;clangCodeGen;clangAnalysis;clangEdit;clangRewrite;clangARCMigrate;clangDriver;clangSerialization;clangRewriteFrontend;clangFrontend;clangFrontendTool;clangToolingCore;clangToolingInclusions;clangToolingRefactoring;clangToolingASTDiff;clangToolingSyntax;clangDependencyScanning;clangTransformer;clangTooling;clangDirectoryWatcher;clangIndex;clangIndexSerialization;clangStaticAnalyzerCore;clangStaticAnalyzerCheckers;clangStaticAnalyzerFrontend;clangFormat;clangTesting;diagtool;clang;clang-format;clangHandleCXX;clangHandleLLVM;clang-offload-bundler;clang-offload-wrapper;clang-scan-deps;clang-rename;clang-refactor;clang-cpp;clang-check;clang-extdef-mapping;libclang")
set(CLANG_CMAKE_DIR "${CLANG_INSTALL_PREFIX}/lib/cmake/clang")
set(CLANG_INCLUDE_DIRS "${CLANG_INSTALL_PREFIX}/include")
set(CLANG_LINK_CLANG_DYLIB "OFF")

# Provide all our library targets to users.
include("${CLANG_CMAKE_DIR}/ClangTargets.cmake")

# By creating clang-tablegen-targets here, subprojects that depend on Clang's
# tablegen-generated headers can always depend on this target whether building
# in-tree with Clang or not.
if(NOT TARGET clang-tablegen-targets)
  add_custom_target(clang-tablegen-targets)
endif()
