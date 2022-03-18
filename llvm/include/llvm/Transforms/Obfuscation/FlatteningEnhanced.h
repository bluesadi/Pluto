#ifndef LLVM_FLATTENING_ENHANCED_H
#define LLVM_FLATTENING_ENHANCED_H

#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include<list>
#include<vector>

namespace llvm
{
    struct TreeNode
	{
		unsigned int val=0,limit=0,l=0,r=0;
		TreeNode *left=NULL,*right=NULL;
	};
    class MyFlatten : public FunctionPass
    {
        public:
            static char ID;
            bool enable;

            MyFlatten(bool enable) : FunctionPass(ID)
            {
                this->enable = enable;
            }

            std::list<TreeNode*>::iterator randomElement(std::list<TreeNode*> *x);
            void expandNode(TreeNode *node);
            int genRandomTree(TreeNode *node,int node_limit);
            void walkTree(TreeNode *node);
            bool allocNode(TreeNode *node,unsigned int l,unsigned int r);
            BasicBlock *createRandomBasicBlock(TreeNode *node,Function *f,Value *var,std::vector<BasicBlock*>::iterator &iter,std::map<BasicBlock*,TreeNode*> *bb_info);
            bool spawnRandomIf(BasicBlock *from,std::vector<BasicBlock*> *son,Value *var,std::map<BasicBlock*,TreeNode*> *bb_info);
            std::vector<BasicBlock*> *getBlocks(Function *function,std::vector<BasicBlock*> *lists);
            void getAnalysisUsage(AnalysisUsage &AU);
            unsigned int getUniqueNumber(std::vector<unsigned int> *rand_list);
            static bool valueEscapes(Instruction *Inst);
            void DoFlatten(Function *f,int seed,int enderNum);
            bool runOnFunction(Function &function);

    };
    FunctionPass* createFlatteningEnhancedPass(bool enable);
}

#endif // LLVM_FLATTENING_H