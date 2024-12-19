#include "../lab1/sim.h"
#include "ForgeLexer.h"
#include "ForgeParser.h"
#include "ForgeVisitor.h"
#include "antlr4-runtime.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include <any>
#include <iostream>
using namespace llvm;

struct TreeLLVMWalker : public ForgeVisitor {
  std::vector<std::map<std::string, Value *>> vars;
  Function *currFunc;
  LLVMContext *ctxLLVM;
  Module *module;
  IRBuilder<> *builder;
  Type *int32Type;
  TreeLLVMWalker(LLVMContext *ctxLLVM, IRBuilder<> *builder, Module *module)
      : ctxLLVM(ctxLLVM), builder(builder), module(module) {
    int32Type = Type::getInt32Ty(*ctxLLVM);
  }
      Value *searchVar(const std::string &name) {
    outs() << "searchVar: " << name << "\n";
    for (auto it = vars.rbegin(); it != vars.rend(); ++it) {
      if (auto find = it->find(name); find != it->end()) {
        return find->second;
      }
    }
    // Conflict resolving: node: (expr) <-> (ID)
    Function *func = module->getFunction(name);
    if (!func || func->arg_size() > 0) {
      outs() << "[Error] Can't find variable: " << name << "\n";
      return nullptr;
    }
    outs() << "Change to FuncCall: " << name << "\n";
    return (Value *)builder->CreateCall(func);
  }

  antlrcpp::Any visitExpr(ForgeParser::ExprContext *ctx) override {
    outs() << "visitExpr: ";
    // ID
    if (ctx->NAME()) {
      outs() << ctx->NAME()->getText() << "\n";
      return searchVar(ctx->NAME()->getText());
    }
    // INT
    if (ctx->INT()) {
      outs() << ctx->INT()->getText() << "\n";
      return (Value *)builder->getInt32(std::stoi(ctx->INT()->getText()));
    }
    // '-' expr
    if (ctx->children.size() == 2) {
      outs() << "neg\n";
      return builder->CreateNeg(std::any_cast<Value*>(visit(ctx->children[1])));
    }
    // '(' expr ')'
    if (ctx->children[0]->getText().at(0) == '(') {
      outs() << "()\n";
      return visit(ctx->children[1]);
    }
    // ( '*' | '/') expr expr
    // ( '+' | '-') expr expr
    outs() << ctx->children[0]->getText() << "\n";
    Value *lhs = std::any_cast<Value*>(visit(ctx->children[1]));
    Value *rhs = std::any_cast<Value*>(visit(ctx->children[2]));
    switch (ctx->children[0]->getText().at(0)) {
    case '*':
      return builder->CreateMul(lhs, rhs);
    case '/':
      return builder->CreateSDiv(lhs, rhs);
    case '+':
      return builder->CreateAdd(lhs, rhs);
    case '-':
      return builder->CreateSub(lhs, rhs);
    default:
      break;
    }
    return nullptr;
  }
};

int main(int argc, const char *argv[]) {
  if (argc != 2) {
    outs() << "[ERROR] Need 1 argument: file with Forge\n";
    return 1;
  }
  // Open file
  std::ifstream stream;
  stream.open(argv[1]);

  // Provide the input text in a stream
  antlr4::ANTLRInputStream input(stream);

  // Create a lexer from the input
  ForgeLexer lexer(&input);

  // Create a token stream from the lexer
  antlr4::CommonTokenStream tokens(&lexer);

  // Create a parser from the token stream
  ForgeParser parser(&tokens);

  // Display the parse tree
//   outs() << parser.program()->toStringTree() << "\n";
//   return 0;

  LLVMContext context;
  Module *module = new Module("top", context);
  IRBuilder<> builder(context);

  TreeLLVMWalker walker(&context, &builder, module);
//   walker.visitProgram(parser.program());

  outs() << "[LLVM IR]\n";
  module->print(outs(), nullptr);
  outs() << "\n";
  bool verif = verifyModule(*module, &outs());
  outs() << "[VERIFICATION] " << (!verif ? "OK\n\n" : "FAIL\n\n");

  Function *appFunc = module->getFunction("app");
  if (appFunc == nullptr) {
    outs() << "Can't find app function\n";
    return -1;
  }

  // LLVM IR Interpreter
  outs() << "[EE] Run\n";
  InitializeNativeTarget();
  InitializeNativeTargetAsmPrinter();

  ExecutionEngine *ee = EngineBuilder(std::unique_ptr<Module>(module)).create();
  ee->InstallLazyFunctionCreator([=](const std::string &fnName) -> void * {
    if (fnName == "PUT_PIXEL") {
      return reinterpret_cast<void *>(simPutPixel);
    }
    if (fnName == "FLUSH") {
      return reinterpret_cast<void *>(simFlush);
    }
    return nullptr;
  });
  ee->finalizeObject();

  simInit();

  ArrayRef<GenericValue> noargs;
  GenericValue v = ee->runFunction(appFunc, noargs);
  outs() << "[EE] Result: " << v.IntVal << "\n";

  simExit();

  return 0;
}