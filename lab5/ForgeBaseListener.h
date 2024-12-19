
// Generated from Forge.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "ForgeListener.h"


/**
 * This class provides an empty implementation of ForgeListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ForgeBaseListener : public ForgeListener {
public:

  virtual void enterExpr(ForgeParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(ForgeParser::ExprContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

