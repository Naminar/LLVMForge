
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

  virtual std::any visitExpr(ForgeParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }


};

