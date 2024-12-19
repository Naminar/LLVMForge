
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

  virtual void enterProgram(ForgeParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(ForgeParser::ProgramContext * /*ctx*/) override { }

  virtual void enterBlock(ForgeParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(ForgeParser::BlockContext * /*ctx*/) override { }

  virtual void enterSetBColor(ForgeParser::SetBColorContext * /*ctx*/) override { }
  virtual void exitSetBColor(ForgeParser::SetBColorContext * /*ctx*/) override { }

  virtual void enterVarDecl(ForgeParser::VarDeclContext * /*ctx*/) override { }
  virtual void exitVarDecl(ForgeParser::VarDeclContext * /*ctx*/) override { }

  virtual void enterRandGet(ForgeParser::RandGetContext * /*ctx*/) override { }
  virtual void exitRandGet(ForgeParser::RandGetContext * /*ctx*/) override { }

  virtual void enterAscendLoop(ForgeParser::AscendLoopContext * /*ctx*/) override { }
  virtual void exitAscendLoop(ForgeParser::AscendLoopContext * /*ctx*/) override { }

  virtual void enterIterLoop(ForgeParser::IterLoopContext * /*ctx*/) override { }
  virtual void exitIterLoop(ForgeParser::IterLoopContext * /*ctx*/) override { }

  virtual void enterGradLoop(ForgeParser::GradLoopContext * /*ctx*/) override { }
  virtual void exitGradLoop(ForgeParser::GradLoopContext * /*ctx*/) override { }

  virtual void enterXLoop(ForgeParser::XLoopContext * /*ctx*/) override { }
  virtual void exitXLoop(ForgeParser::XLoopContext * /*ctx*/) override { }

  virtual void enterYLoop(ForgeParser::YLoopContext * /*ctx*/) override { }
  virtual void exitYLoop(ForgeParser::YLoopContext * /*ctx*/) override { }

  virtual void enterDescendLoop(ForgeParser::DescendLoopContext * /*ctx*/) override { }
  virtual void exitDescendLoop(ForgeParser::DescendLoopContext * /*ctx*/) override { }

  virtual void enterExpr(ForgeParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(ForgeParser::ExprContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

