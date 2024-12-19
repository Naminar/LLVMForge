
// Generated from Forge.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "ForgeVisitor.h"


/**
 * This class provides an empty implementation of ForgeVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ForgeBaseVisitor : public ForgeVisitor {
public:

  virtual std::any visitProgram(ForgeParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(ForgeParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSetBColor(ForgeParser::SetBColorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDecl(ForgeParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRandGet(ForgeParser::RandGetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAscendLoop(ForgeParser::AscendLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIterLoop(ForgeParser::IterLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGradLoop(ForgeParser::GradLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitXLoop(ForgeParser::XLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitYLoop(ForgeParser::YLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDescendLoop(ForgeParser::DescendLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr(ForgeParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }


};

