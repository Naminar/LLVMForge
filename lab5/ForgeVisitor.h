
// Generated from Forge.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "ForgeParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ForgeParser.
 */
class  ForgeVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ForgeParser.
   */
    virtual std::any visitProgram(ForgeParser::ProgramContext *context) = 0;

    virtual std::any visitBlock(ForgeParser::BlockContext *context) = 0;

    virtual std::any visitSetBColor(ForgeParser::SetBColorContext *context) = 0;

    virtual std::any visitVarDecl(ForgeParser::VarDeclContext *context) = 0;

    virtual std::any visitRandGet(ForgeParser::RandGetContext *context) = 0;

    virtual std::any visitAscendLoop(ForgeParser::AscendLoopContext *context) = 0;

    virtual std::any visitIterLoop(ForgeParser::IterLoopContext *context) = 0;

    virtual std::any visitGradLoop(ForgeParser::GradLoopContext *context) = 0;

    virtual std::any visitXLoop(ForgeParser::XLoopContext *context) = 0;

    virtual std::any visitYLoop(ForgeParser::YLoopContext *context) = 0;

    virtual std::any visitDescendLoop(ForgeParser::DescendLoopContext *context) = 0;

    virtual std::any visitExpr(ForgeParser::ExprContext *context) = 0;


};

