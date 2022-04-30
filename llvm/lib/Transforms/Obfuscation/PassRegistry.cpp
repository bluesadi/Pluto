#include "llvm/Transforms/Obfuscation/PassRegistry.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Transforms/Obfuscation/HelloWorld.h"
#include "llvm/Transforms/Obfuscation/SplitBasicBlock.h"
#include "llvm/Transforms/Obfuscation/Flattening.h"
#include "llvm/Transforms/Obfuscation/FlatteningEnhanced.h"
#include "llvm/Transforms/Obfuscation/BogusControlFlow.h"
#include "llvm/Transforms/Obfuscation/Substitution.h"
#include "llvm/Transforms/Obfuscation/GlobalsEncryption.h"
#include "llvm/Transforms/Obfuscation/VariableSubstitution.h"
#include "llvm/Transforms/Obfuscation/RandomControlFlow.h"
#include "llvm/Transforms/Obfuscation/TrapAngr.h"
#include "llvm/Transforms/Obfuscation/MBAObfuscation.h"
#include "llvm/Transforms/Utils.h"
#include "llvm/Transforms/IPO.h"

using namespace llvm;

cl::opt<bool> RunHelloWorld("hlw", cl::init(false), cl::desc("Enable the HelloWorld pass"));

cl::opt<bool> RunFlattening("fla", cl::init(false), cl::desc("Enable the Flattening pass"));

cl::opt<bool> RunFlatteningEnhanced("fla-ex", cl::init(false), cl::desc("Enable the Enhanced Flattening pass"));

cl::opt<bool> RunBogusControlFlow("bcf", cl::init(false), cl::desc("Enable the BogusControlFlow pass"));

cl::opt<bool> RunSubstitution("sub", cl::init(false), cl::desc("Enable the Substitution pass"));

cl::opt<bool> RunGlobalsEncryption("gle", cl::init(false), cl::desc("Enable the GlobalsEncryption pass"));

cl::opt<bool> RunVariableSubstitution("vsb", cl::init(false), cl::desc("Enable the VariableSubstitution pass"));

cl::opt<bool> RunRandomControlFlow("rcf", cl::init(false), cl::desc("Enable the RandomControlFlow pass"));

cl::opt<bool> RunTrapAngr("trap-angr", cl::init(false), cl::desc("Enable the TrapAngr pass"));

cl::opt<bool> RunMBAObfuscation("mba", cl::init(false), cl::desc("Enable the MBAObfuscation pass"));

void llvm::registerAllPasses(legacy::PassManagerBase &MPM){
    MPM.add(createHelloWorldPass(RunHelloWorld));
    MPM.add(createSplitBasicBlockPass());
    MPM.add(createLowerSwitchPass());
    MPM.add(createFlatteningPass(RunFlattening));
    MPM.add(createFlatteningEnhancedPass(RunFlatteningEnhanced));
    MPM.add(craeteBogusControlFlow(RunBogusControlFlow));
    MPM.add(createSubstitutionPass(RunSubstitution));
    MPM.add(createGlobalsEncryptionPass(RunGlobalsEncryption));
    MPM.add(createVariableSubstitutionPass(RunVariableSubstitution));
    MPM.add(createRandomControlFlow(RunRandomControlFlow));
    MPM.add(createTrapAngrPass(RunTrapAngr));
    MPM.add(createLowerSwitchPass());
    MPM.add(createMBAObfuscationPass(RunMBAObfuscation));
    
}