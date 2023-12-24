BUILD_DIR := $(CURDIR)/build
INSTALL_PREFIX := $(CURDIR)/install

TESTS_DIR := tests
TEST_FILES := $(wildcard $(TESTS_DIR)/*.sh)

all: build install check

build:
	mkdir -p $(BUILD_DIR)
	cmake -G Ninja -S llvm -B $(BUILD_DIR) \
	      -DLLVM_ENABLE_PROJECTS="clang" \
	      -DLLVM_INCLUDE_BENCHMARKS=OFF \
	      -DCMAKE_INSTALL_PREFIX=$(INSTALL_PREFIX) \
	      -DCMAKE_C_COMPILER=gcc \
	      -DCMAKE_CXX_COMPILER=g++ \
	      -DCMAKE_BUILD_TYPE=Release
	ninja -j`nproc` -C $(BUILD_DIR)

install: build
	mkdir -p $(INSTALL_PREFIX)
	ninja -j`nproc` -C $(BUILD_DIR) install

check:
	@echo "Running tests..."
	@SUCCESS_COUNT=0; \
	for file in $(TEST_FILES); do \
		./$$file; \
		if [ $$? -eq 0 ]; then \
			echo "\e[32m$$file: PASS\e[0m"; \
			SUCCESS_COUNT=$$((SUCCESS_COUNT + 1)); \
        else \
			echo "\e[31m$$file: FAIL\e[0m"; \
		fi \
	done; \
	echo "Total tests: $(words $(TEST_FILES))"; \
	echo "Success count: $$SUCCESS_COUNT"

.PHONY: all build install check