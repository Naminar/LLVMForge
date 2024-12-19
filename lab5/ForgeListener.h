
// Generated from Forge.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "ForgeParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by ForgeParser.
 */
class  ForgeListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterExpr(ForgeParser::ExprContext *ctx) = 0;
  virtual void exitExpr(ForgeParser::ExprContext *ctx) = 0;


};

