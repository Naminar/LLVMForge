#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Value.h"

using namespace llvm;

int main() {
    LLVMContext Context;
    Module* Module = new llvm::Module("my_module", Context);
    IRBuilder<> Builder(Context);

    // Define the i32 type and the array type [50 x i32]
    Type* i32Type = Builder.getInt32Ty();
    ArrayType* arrayType = ArrayType::get(i32Type, 50);

    // Create a pointer type for the array, since GEP works with pointers
    PointerType* ptrToArrayType = PointerType::get(arrayType, 0);

    // Create dummy function to insert instructions into
    FunctionType* funcType = FunctionType::get(Builder.getVoidTy(), false);
    Function* func = Function::Create(funcType, Function::ExternalLinkage, "dummy_function", Module);
    BasicBlock* entry = BasicBlock::Create(Context, "entry", func);
    Builder.SetInsertPoint(entry);

    // Allocate space for %2 (ptrArray), and %16 (index)
    Value* ptrArray = Builder.CreateAlloca(ptrToArrayType, nullptr, "ptrArray");
    Value* index = Builder.CreateAlloca(Builder.getInt64Ty(), nullptr, "index");

    // Load the actual values, since alloca returns pointers to these values
    Value* ptrArrayLoaded = Builder.CreateLoad(ptrToArrayType, ptrArray, "ptrArrayLoaded");
    Value* indexLoaded = Builder.CreateLoad(Builder.getInt64Ty(), index, "indexLoaded");

    // Define the first index as a constant integer of 0
    Value* idx0 = Builder.getInt64(0);

    // Create the GEP instruction - pass the loaded pointer and the indices
    Value* gep = Builder.CreateInBoundsGEP(arrayType, ptrArrayLoaded, {idx0, indexLoaded}, "gep");

    // Finalize the function by returning void
    Builder.CreateRetVoid();

    // Output the module's IR
    Module->print(llvm::outs(), nullptr);
    delete Module;
    return 0;
}
