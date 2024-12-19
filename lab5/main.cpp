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
  Type *voidType;

  TreeLLVMWalker(LLVMContext *ctxLLVM, IRBuilder<> *builder, Module *module)
      : ctxLLVM(ctxLLVM), builder(builder), module(module) {
    int32Type = Type::getInt32Ty(*ctxLLVM);
   voidType = Type::getVoidTy(*ctxLLVM);
  }
    Value *registerVar(const std::string &name, Value *val) {
      outs() << "registerVar: " << name << "\n";
      vars.back()[name] = val;
      return val;
    }
    Value *searchVar(const std::string &name) {
      outs() << "searchVar: " << name << "\n";
      for (auto it = vars.rbegin(); it != vars.rend(); ++it) {
        if (auto find = it->find(name); find != it->end()) {
          return find->second;
        }
      }
      outs() << "[Error] Can't find variable: " << name << "\n";
      return nullptr;
    }

  antlrcpp::Any visitProgram(ForgeParser::
  ForgeParser::ProgramContext *ctx) override {
        outs() << "visitProgram\n";

    ArrayRef<Type *> simPutPixelParamTypes = {int32Type, int32Type, int32Type};
    FunctionType *simPutPixelType =
        FunctionType::get(voidType, simPutPixelParamTypes, false);
    module->getOrInsertFunction("simPutPixel", simPutPixelType);

    FunctionType *simFlushType = FunctionType::get(voidType, false);
    module->getOrInsertFunction("simFlush", simFlushType);

      FunctionType *SimRandType = FunctionType::get(Type::getInt32Ty(
        *ctxLLVM), false); 
      module->getOrInsertFunction("simRand", SimRandType);


    for (auto it : ctx->
    block()) {
      visitBlock(it);
    }    
    return nullptr;
  }

  antlrcpp::Any visitBlock(ForgeParser::BlockContext *ctx) override {
    outs() << "visitBlock\n";
    std::string name = ctx->NAME()->getText();
    outs() << name << "\n";
    vars.push_back({});

    FunctionType *funcType = FunctionType::get(voidType, false);
    Function *func = Function::Create(funcType, Function::ExternalLinkage,
                                      name, module);
    BasicBlock *entryBB = BasicBlock::Create(*ctxLLVM, "entry", func);
    builder->SetInsertPoint(entryBB);
    currFunc = func;

    visitSetBColor(ctx->setBColor());
    
    for (int arg = 0; arg < ctx->varDecl().size(); arg++) {
      visitVarDecl(ctx->varDecl()[arg]);
    }
    
    for (int arg = 0; arg < ctx->ascendLoop().size(); arg++) {
      visitAscendLoop(ctx->ascendLoop()[arg]);
    }

    for (int arg = 0; arg < ctx->descendLoop().size(); arg++) {
      visitDescendLoop(ctx->descendLoop()[arg]);
    }

    Value *res = nullptr;
    builder->CreateRet(res);
    return nullptr;
  }

 antlrcpp::Any visitSetBColor(ForgeParser::SetBColorContext *ctx) override {
    outs() << "visitSetBColor\n";
    std::string INT = ctx->INT()->getText();
    outs() << INT << "\n";
    Value *val = ConstantInt::get(Type::getInt32Ty(*ctxLLVM), std::stoi(INT));
    registerVar("bColor", val);
    return nullptr;
  }

 
 antlrcpp::Any visitVarDecl(ForgeParser::VarDeclContext *ctx) override {
    outs() << "visitVarDecl\n";
    std::string name = ctx->NAME()->getText();
    outs() << name << "\n";
    int val;
    Value *val_v;

    // if(ctx->INT()) {
    //   outs() << ctx->INT()->getText() << "\n";
    //   val = std::stoi(ctx->INT()->getText());
    //   val_v = ConstantInt::get(Type::getInt32Ty(*ctxLLVM), val);
    // } 

    if(ctx->randGet()) {
      val_v = std::any_cast<Value*>(visitRandGet(ctx->randGet()));
    }

    if(ctx->expr()) {
      val_v = std::any_cast<Value*>(visitExpr(ctx->expr()));
    }
    
    registerVar(name, val_v);
    return nullptr;
 }

 antlrcpp::Any 
 visitRandGet(ForgeParser::RandGetContext *ctx) override {
    outs() << "visitRandGet\n";
    outs() << ctx->INT()->getText() << "\n";
    int val = std::stoi(ctx->INT()->getText());
    Function *func = module->getFunction("simRand");

    return (Value *) builder->CreateSRem((Value *)builder->CreateCall(func), ConstantInt::get(Type::getInt32Ty(*ctxLLVM), val));
 }

 antlrcpp::Any visitAscendLoop(ForgeParser::AscendLoopContext *ctx) override {
    outs() << "visitAscendLoop\n";
    Value* iter_v;
    Value* grad_v;
    Value* x_v;
    Value* y_v;
    if(ctx->iterLoop())
      iter_v = std::any_cast<Value*>(visitIterLoop(ctx->iterLoop()));
    if(ctx->gradLoop())
      grad_v = std::any_cast<Value*>(visitGradLoop(ctx->gradLoop()));
    if(ctx->xLoop())
      x_v = std::any_cast<Value*>( visitXLoop(ctx->xLoop()));
    if(ctx->yLoop())
      y_v = std::any_cast<Value*>( visitYLoop(ctx->yLoop()));

    BasicBlock *entry = builder->GetInsertBlock();
    BasicBlock *loopCond = BasicBlock::Create(*ctxLLVM, "loop.cond", 
    currFunc);
    BasicBlock *loopBody = BasicBlock::Create(*ctxLLVM, "loop.body", currFunc);
    BasicBlock *loopEnd = BasicBlock::Create(*ctxLLVM, "loop.end", currFunc);
    
    Value *stars_x = iter_v;
    Value *stars_y = y_v;
    Value *x_l_gradient = grad_v;
    
    Function *simPutPixel = module->getFunction("simPutPixel");
    Function *simFlush = module->getFunction("simFlush");

    builder->CreateBr(loopCond);
    builder->SetInsertPoint(loopCond);
    
    PHINode *x_l = builder->CreatePHI(builder->getInt32Ty(), 2, "x_l");
    x_l->addIncoming(stars_x, entry);

    Value *cond = builder->CreateICmpSGT(x_l, builder->getInt32(0), "cond");
    builder->CreateCondBr(cond, loopBody, loopEnd);

    builder->SetInsertPoint(loopBody);
    // simPutPixel(x_l, stars_y, 0x0000FFFF + x_l * (16 + x_l_gradient));
    Value *color = builder->CreateAdd(
        builder->getInt32(0x0000FFFF),
        builder->CreateMul(x_l, builder->CreateAdd(builder->getInt32(16), grad_v)),
        "color");
    
    builder->CreateCall(simPutPixel, {x_l, stars_y, color});
    builder->CreateCall(simFlush, {});
    
    Value *x_l_next = builder->CreateSub(x_l, builder->getInt32(1), "x_l.next");
    x_l->addIncoming(x_l_next, loopBody);
    
    builder->CreateBr(loopCond);
    builder->SetInsertPoint(loopEnd);

    return nullptr;
 }

 antlrcpp::Any visitDescendLoop(ForgeParser::DescendLoopContext *ctx) override {
    outs() << "visitDescendLoop\n";
    Value* iter_v;
    Value* grad_v;
    Value* x_v;
    Value* y_v;
    if(ctx->iterLoop())
      iter_v = std::any_cast<Value*>(visitIterLoop(ctx->iterLoop()));
    if(ctx->gradLoop())
      grad_v = std::any_cast<Value*>(visitGradLoop(ctx->gradLoop()));
    if(ctx->xLoop())
      x_v = std::any_cast<Value*>( visitXLoop(ctx->xLoop()));
    if(ctx->yLoop())
      y_v = std::any_cast<Value*>( visitYLoop(ctx->yLoop()));
    
    BasicBlock *entry = builder->GetInsertBlock();
    BasicBlock *loopCond = BasicBlock::Create(*ctxLLVM, "loop.cond", currFunc);
    BasicBlock *loopBody = BasicBlock::Create(*ctxLLVM, "loop.body", currFunc);
    BasicBlock *loopEnd = BasicBlock::Create(*ctxLLVM, "loop.end", currFunc);

    Value *stars_x = iter_v;
    Value *stars_y = y_v;
    Value *x_r_gradient = grad_v;
    Value *border = x_v;
    
    Function *simPutPixel = module->getFunction("simPutPixel");
    Function *simFlush = module->getFunction("simFlush");

    builder->CreateBr(loopCond);
    builder->SetInsertPoint(loopCond);


    PHINode *x_r = builder->CreatePHI(builder->getInt32Ty(), 2, "x_r");
    x_r->addIncoming(stars_x, entry);

    Value *cond = builder->CreateICmpSLT(x_r, border, "cond");
    builder->CreateCondBr(cond, loopBody, loopEnd);

    builder->SetInsertPoint(loopBody);
    // simPutPixel(x_r, stars_y, 0x0000FFFF + x_r * (16 + x_r_gradient));
    Value *color = builder->CreateAdd(
        builder->getInt32(0x0000FFFF),
        builder->CreateMul(x_r, builder->CreateAdd(builder->getInt32(16), x_r_gradient)),
        "color");
    
    builder->CreateCall(simPutPixel, {x_r, stars_y, color});
    builder->CreateCall(simFlush, {});
    
    Value *x_r_next = builder->CreateAdd(x_r, builder->getInt32(1), "x_r.next");
    x_r->addIncoming(x_r_next, loopBody);

    builder->CreateBr(loopCond);
    builder->SetInsertPoint(loopEnd);

    return nullptr;
 }

  antlrcpp::Any visitIterLoop(ForgeParser::IterLoopContext *ctx) override {
    outs() << "visitIterLoop\n";
    Value* val_v;
    if(ctx->INT()) {
      outs() << ctx->INT()->getText() << "\n";
      int val = std::stoi(ctx->INT()->getText());
      val_v = ConstantInt::get(Type::getInt32Ty(*ctxLLVM), val);

    }
      
    if(ctx->NAME()) {
      outs() << ctx->NAME()->getText() << "\n";
      val_v = searchVar(ctx->NAME()->getText());
      }
    return val_v;  
  }

  antlrcpp::Any visitGradLoop(ForgeParser::GradLoopContext *ctx) override {
    outs() << "visitGradLoop\n";
    Value* val_v;
    if(ctx->NAME()) {
      outs() << ctx->NAME()->getText() << "\n";
      val_v = searchVar(ctx->NAME()->getText());
    }
    return val_v;
  }

  antlrcpp::Any visitXLoop(ForgeParser::XLoopContext *ctx) override {
    outs() << "visitXLoop\n";
   Value* val_v;
    if(ctx->NAME()) {
      outs() << ctx->NAME()->getText() << "\n";
      val_v = searchVar(ctx->NAME()->getText());
    }
    return val_v;
  }

  antlrcpp::Any visitYLoop(ForgeParser::YLoopContext *ctx) override {
    outs() << "visitYLoop\n";
    Value* val_v;
    if(ctx->NAME()) {
      outs() << ctx->NAME()->getText() << "\n";
      val_v = searchVar(ctx->NAME()->getText());
    }
    return val_v;
  }

  antlrcpp::Any visitExpr(ForgeParser::ExprContext *ctx) override {
    outs() << "visitExpr: ";
    // NAME
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
  walker.visitProgram(parser.program());

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
    if (fnName == "simPutPixel") {
      return reinterpret_cast<void *>(simPutPixel);
    }
    if (fnName == "simFlush") {
      return reinterpret_cast<void *>(simFlush);
    }
    if (fnName == "simRand") {
      return reinterpret_cast<void *>(simRand);
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