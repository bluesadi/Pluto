#ifndef LLVM_GLOBALS_ENCRYPTION_H
#define LLVM_GLOBALS_ENCRYPTION_H

#include "llvm/Pass.h"
#include "llvm/IR/Module.h"

namespace llvm{
    struct EncryptedGV{
        GlobalVariable *GV;
        uint64_t key;
        uint32_t len;
    };

    class GlobalsEncryption : public ModulePass{
        public:
            static char ID;
            bool enable;

            GlobalsEncryption(bool enable) : ModulePass(ID){
                this->enable = enable;
            }

            bool runOnModule(Module &M) override;

            void insertArrayDecryption(Module &M, EncryptedGV encGV);

            void insertIntDecryption(Module &M, EncryptedGV encGV);

    };

    ModulePass* createGlobalsEncryptionPass(bool enable);
}

#endif // LLVM_GLOBALS_ENCRYPTION_H