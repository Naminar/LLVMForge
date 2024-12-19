
// Generated from Forge.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "ForgeParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by ForgeParser.
 */
class  ForgeListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(ForgeParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(ForgeParser::ProgramContext *ctx) = 0;

  virtual void enterBlock(ForgeParser::BlockContext *ctx) = 0;
  virtual void exitBlock(ForgeParser::BlockContext *ctx) = 0;

  virtual void enterSetBColor(ForgeParser::SetBColorContext *ctx) = 0;
  virtual void exitSetBColor(ForgeParser::SetBColorContext *ctx) = 0;

  virtual void enterVarDecl(ForgeParser::VarDeclContext *ctx) = 0;
  virtual void exitVarDecl(ForgeParser::VarDeclContext *ctx) = 0;

  virtual void enterRandGet(ForgeParser::RandGetContext *ctx) = 0;
  virtual void exitRandGet(ForgeParser::RandGetContext *ctx) = 0;

  virtual void enterAscendLoop(ForgeParser::AscendLoopContext *ctx) = 0;
  virtual void exitAscendLoop(ForgeParser::AscendLoopContext *ctx) = 0;

  virtual void enterIterLoop(ForgeParser::IterLoopContext *ctx) = 0;
  virtual void exitIterLoop(ForgeParser::IterLoopContext *ctx) = 0;

  virtual void enterGradLoop(ForgeParser::GradLoopContext *ctx) = 0;
  virtual void exitGradLoop(ForgeParser::GradLoopContext *ctx) = 0;

  virtual void enterXLoop(ForgeParser::XLoopContext *ctx) = 0;
  virtual void exitXLoop(ForgeParser::XLoopContext *ctx) = 0;

  virtual void enterYLoop(ForgeParser::YLoopContext *ctx) = 0;
  virtual void exitYLoop(ForgeParser::YLoopContext *ctx) = 0;

  virtual void enterDescendLoop(ForgeParser::DescendLoopContext *ctx) = 0;
  virtual void exitDescendLoop(ForgeParser::DescendLoopContext *ctx) = 0;

  virtual void enterExpr(ForgeParser::ExprContext *ctx) = 0;
  virtual void exitExpr(ForgeParser::ExprContext *ctx) = 0;


};

