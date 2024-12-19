
// Generated from NodeLang.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "NodeLangParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by NodeLangParser.
 */
class  NodeLangVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by NodeLangParser.
   */
    virtual std::any visitProgram(NodeLangParser::ProgramContext *context) = 0;

    virtual std::any visitNodeDecl(NodeLangParser::NodeDeclContext *context) = 0;

    virtual std::any visitFuncDecl(NodeLangParser::FuncDeclContext *context) = 0;

    virtual std::any visitNode(NodeLangParser::NodeContext *context) = 0;

    virtual std::any visitVarDecl(NodeLangParser::VarDeclContext *context) = 0;

    virtual std::any visitExpr(NodeLangParser::ExprContext *context) = 0;


};

