#pragma once

#include "llvm/IR/PassManager.h"

using namespace llvm;

ModulePassManager buildObfuscationPipeline();

ModulePassManager buildLTOObfuscationPipeline();