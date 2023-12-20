# Makefile

BUILD_DIR := $(CURDIR)/build
INSTALL_PREFIX := $(CURDIR)/install
TESTS_BUILD_DIR := $(CURDIR)/tests/build

all: build install tests

build:
	mkdir -p $(BUILD_DIR)
	cmake -G Ninja -S llvm -B $(BUILD_DIR) \
	      -DLLVM_ENABLE_PROJECTS="clang" \
	      -DLLVM_INCLUDE_BENCHMARKS=OFF \
	      -DCMAKE_INSTALL_PREFIX=$(INSTALL_PREFIX) \
	      -DCMAKE_C_COMPILER=gcc \
	      -DCMAKE_CXX_COMPILER=g++ \
	      -DCMAKE_BUILD_TYPE=Release
	ninja -C $(BUILD_DIR)

install: build
	mkdir -p $(INSTALL_PREFIX)
	ninja -C $(BUILD_DIR) install

tests: install
	mkdir -p $(TESTS_BUILD_DIR)
	cmake -G Ninja -S tests -B $(TESTS_BUILD_DIR) \
	      -DCMAKE_C_COMPILER=$(INSTALL_PREFIX)/bin/clang \
	      -DCMAKE_CXX_COMPILER=$(INSTALL_PREFIX)/bin/clang++
	ninja -C $(TESTS_BUILD_DIR)
	ctest --test-dir $(TESTS_BUILD_DIR)

.PHONY: all build install tests