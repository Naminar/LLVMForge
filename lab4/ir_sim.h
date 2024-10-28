
#include "../lab1/sim.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace llvm;

const int REG_FILE_SIZE = 20;
uint32_t REG_FILE[REG_FILE_SIZE];

void doCallSrem(int arg1, int arg2) {
    outs() << "\tcallSrem\n";
    REG_FILE[arg2] = simRand() % arg1;
}

void doTcall(int arg1) {
    outs() << "\tctcall\n";
    REG_FILE[arg1] = simRand();
}

void doCmpSgt(int arg1, int arg2, int arg3) {
    outs() << "\tcmpSgt\n";
    REG_FILE[arg3] = REG_FILE[arg1] > arg2; 
}

void doSremAdd(int arg1, int arg2, int arg3, int arg4) {
    outs() << "\tsremAdd\n";
    REG_FILE[arg4] = REG_FILE[arg1] % arg2 + arg3;
}

void doMov(int arg1, int arg2) {
    outs() << "\tmov\n";
    REG_FILE[arg2] = REG_FILE[arg1];
}

void doAdd(int arg1, int arg2, int arg3) {
    outs() << "\tadd\n";
    REG_FILE[arg3] = REG_FILE[arg1] + arg2;
}

void doMullAddVal(int arg1, int arg2, int arg3, int arg4) {
    outs() << "\tmullAddVal\n";
    REG_FILE[arg4] = REG_FILE[arg1] * REG_FILE[arg2] + arg3;
}

void doCtcall(int arg1, int arg2, int arg3) {
    outs() << "\tctcall\n";
    simPutPixel(REG_FILE[arg1], REG_FILE[arg2], REG_FILE[arg3]);
    simFlush();
}

void doAddCmpUgtContinues(int arg1, int arg2, int arg3, int arg4, int arg5) {
    outs() << "\taddCmpUgtContinues\n";
    REG_FILE[arg4] = REG_FILE[arg1] + arg2;
    REG_FILE[arg5] = unsigned(REG_FILE[arg1]) > unsigned(arg3);
}