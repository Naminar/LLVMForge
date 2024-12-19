
// Generated from NodeLang.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "NodeLangVisitor.h"


/**
 * This class provides an empty implementation of NodeLangVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  NodeLangBaseVisitor : public NodeLangVisitor {
public:

  virtual std::any visitProgram(NodeLangParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNodeDecl(NodeLangParser::NodeDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncDecl(NodeLangParser::FuncDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNode(NodeLangParser::NodeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDecl(NodeLangParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr(NodeLangParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }


};

