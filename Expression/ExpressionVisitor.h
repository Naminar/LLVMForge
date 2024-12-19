
// Generated from Expression.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "ExpressionParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ExpressionParser.
 */
class  ExpressionVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ExpressionParser.
   */
    virtual std::any visitExpr(ExpressionParser::ExprContext *context) = 0;


};

