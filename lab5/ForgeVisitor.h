
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
    virtual std::any visitExpr(ForgeParser::ExprContext *context) = 0;


};

