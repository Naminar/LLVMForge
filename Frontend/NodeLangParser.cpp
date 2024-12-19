
// Generated from NodeLang.g4 by ANTLR 4.13.0


#include "NodeLangListener.h"
#include "NodeLangVisitor.h"

#include "NodeLangParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct NodeLangParserStaticData final {
  NodeLangParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  NodeLangParserStaticData(const NodeLangParserStaticData&) = delete;
  NodeLangParserStaticData(NodeLangParserStaticData&&) = delete;
  NodeLangParserStaticData& operator=(const NodeLangParserStaticData&) = delete;
  NodeLangParserStaticData& operator=(NodeLangParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag nodelangParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
NodeLangParserStaticData *nodelangParserStaticData = nullptr;

void nodelangParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (nodelangParserStaticData != nullptr) {
    return;
  }
#else
  assert(nodelangParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<NodeLangParserStaticData>(
    std::vector<std::string>{
      "program", "nodeDecl", "funcDecl", "node", "varDecl", "expr"
    },
    std::vector<std::string>{
      "", "'('", "'NODE'", "')'", "'-'", "'*'", "'/'", "'+'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "ID", "INT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,10,74,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,1,0,4,0,14,
  	8,0,11,0,12,0,15,1,1,1,1,1,1,1,1,3,1,22,8,1,1,1,1,1,1,2,1,2,1,2,5,2,29,
  	8,2,10,2,12,2,32,9,2,1,2,1,2,4,2,36,8,2,11,2,12,2,37,1,3,1,3,1,3,1,3,
  	1,3,5,3,45,8,3,10,3,12,3,48,9,3,1,3,3,3,51,8,3,1,4,1,4,1,4,1,5,1,5,1,
  	5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,72,8,5,1,5,
  	0,0,6,0,2,4,6,8,10,0,2,1,0,5,6,2,0,4,4,7,7,79,0,13,1,0,0,0,2,17,1,0,0,
  	0,4,25,1,0,0,0,6,50,1,0,0,0,8,52,1,0,0,0,10,71,1,0,0,0,12,14,3,2,1,0,
  	13,12,1,0,0,0,14,15,1,0,0,0,15,13,1,0,0,0,15,16,1,0,0,0,16,1,1,0,0,0,
  	17,18,5,1,0,0,18,21,5,2,0,0,19,22,3,8,4,0,20,22,3,4,2,0,21,19,1,0,0,0,
  	21,20,1,0,0,0,22,23,1,0,0,0,23,24,5,3,0,0,24,3,1,0,0,0,25,26,5,8,0,0,
  	26,30,5,1,0,0,27,29,5,8,0,0,28,27,1,0,0,0,29,32,1,0,0,0,30,28,1,0,0,0,
  	30,31,1,0,0,0,31,33,1,0,0,0,32,30,1,0,0,0,33,35,5,3,0,0,34,36,3,6,3,0,
  	35,34,1,0,0,0,36,37,1,0,0,0,37,35,1,0,0,0,37,38,1,0,0,0,38,5,1,0,0,0,
  	39,51,3,2,1,0,40,51,3,10,5,0,41,42,5,1,0,0,42,46,5,8,0,0,43,45,3,6,3,
  	0,44,43,1,0,0,0,45,48,1,0,0,0,46,44,1,0,0,0,46,47,1,0,0,0,47,49,1,0,0,
  	0,48,46,1,0,0,0,49,51,5,3,0,0,50,39,1,0,0,0,50,40,1,0,0,0,50,41,1,0,0,
  	0,51,7,1,0,0,0,52,53,5,8,0,0,53,54,3,10,5,0,54,9,1,0,0,0,55,56,5,4,0,
  	0,56,72,3,10,5,0,57,58,7,0,0,0,58,59,3,10,5,0,59,60,3,10,5,0,60,72,1,
  	0,0,0,61,62,7,1,0,0,62,63,3,10,5,0,63,64,3,10,5,0,64,72,1,0,0,0,65,66,
  	5,1,0,0,66,67,3,10,5,0,67,68,5,3,0,0,68,72,1,0,0,0,69,72,5,9,0,0,70,72,
  	5,8,0,0,71,55,1,0,0,0,71,57,1,0,0,0,71,61,1,0,0,0,71,65,1,0,0,0,71,69,
  	1,0,0,0,71,70,1,0,0,0,72,11,1,0,0,0,7,15,21,30,37,46,50,71
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  nodelangParserStaticData = staticData.release();
}

}

NodeLangParser::NodeLangParser(TokenStream *input) : NodeLangParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

NodeLangParser::NodeLangParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  NodeLangParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *nodelangParserStaticData->atn, nodelangParserStaticData->decisionToDFA, nodelangParserStaticData->sharedContextCache, options);
}

NodeLangParser::~NodeLangParser() {
  delete _interpreter;
}

const atn::ATN& NodeLangParser::getATN() const {
  return *nodelangParserStaticData->atn;
}

std::string NodeLangParser::getGrammarFileName() const {
  return "NodeLang.g4";
}

const std::vector<std::string>& NodeLangParser::getRuleNames() const {
  return nodelangParserStaticData->ruleNames;
}

const dfa::Vocabulary& NodeLangParser::getVocabulary() const {
  return nodelangParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView NodeLangParser::getSerializedATN() const {
  return nodelangParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

NodeLangParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<NodeLangParser::NodeDeclContext *> NodeLangParser::ProgramContext::nodeDecl() {
  return getRuleContexts<NodeLangParser::NodeDeclContext>();
}

NodeLangParser::NodeDeclContext* NodeLangParser::ProgramContext::nodeDecl(size_t i) {
  return getRuleContext<NodeLangParser::NodeDeclContext>(i);
}


size_t NodeLangParser::ProgramContext::getRuleIndex() const {
  return NodeLangParser::RuleProgram;
}

void NodeLangParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NodeLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void NodeLangParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NodeLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any NodeLangParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NodeLangVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

NodeLangParser::ProgramContext* NodeLangParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, NodeLangParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(13); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(12);
      nodeDecl();
      setState(15); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == NodeLangParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NodeDeclContext ------------------------------------------------------------------

NodeLangParser::NodeDeclContext::NodeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

NodeLangParser::VarDeclContext* NodeLangParser::NodeDeclContext::varDecl() {
  return getRuleContext<NodeLangParser::VarDeclContext>(0);
}

NodeLangParser::FuncDeclContext* NodeLangParser::NodeDeclContext::funcDecl() {
  return getRuleContext<NodeLangParser::FuncDeclContext>(0);
}


size_t NodeLangParser::NodeDeclContext::getRuleIndex() const {
  return NodeLangParser::RuleNodeDecl;
}

void NodeLangParser::NodeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NodeLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNodeDecl(this);
}

void NodeLangParser::NodeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NodeLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNodeDecl(this);
}


std::any NodeLangParser::NodeDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NodeLangVisitor*>(visitor))
    return parserVisitor->visitNodeDecl(this);
  else
    return visitor->visitChildren(this);
}

NodeLangParser::NodeDeclContext* NodeLangParser::nodeDecl() {
  NodeDeclContext *_localctx = _tracker.createInstance<NodeDeclContext>(_ctx, getState());
  enterRule(_localctx, 2, NodeLangParser::RuleNodeDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(17);
    match(NodeLangParser::T__0);
    setState(18);
    match(NodeLangParser::T__1);
    setState(21);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      setState(19);
      varDecl();
      break;
    }

    case 2: {
      setState(20);
      funcDecl();
      break;
    }

    default:
      break;
    }
    setState(23);
    match(NodeLangParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDeclContext ------------------------------------------------------------------

NodeLangParser::FuncDeclContext::FuncDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> NodeLangParser::FuncDeclContext::ID() {
  return getTokens(NodeLangParser::ID);
}

tree::TerminalNode* NodeLangParser::FuncDeclContext::ID(size_t i) {
  return getToken(NodeLangParser::ID, i);
}

std::vector<NodeLangParser::NodeContext *> NodeLangParser::FuncDeclContext::node() {
  return getRuleContexts<NodeLangParser::NodeContext>();
}

NodeLangParser::NodeContext* NodeLangParser::FuncDeclContext::node(size_t i) {
  return getRuleContext<NodeLangParser::NodeContext>(i);
}


size_t NodeLangParser::FuncDeclContext::getRuleIndex() const {
  return NodeLangParser::RuleFuncDecl;
}

void NodeLangParser::FuncDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NodeLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncDecl(this);
}

void NodeLangParser::FuncDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NodeLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncDecl(this);
}


std::any NodeLangParser::FuncDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NodeLangVisitor*>(visitor))
    return parserVisitor->visitFuncDecl(this);
  else
    return visitor->visitChildren(this);
}

NodeLangParser::FuncDeclContext* NodeLangParser::funcDecl() {
  FuncDeclContext *_localctx = _tracker.createInstance<FuncDeclContext>(_ctx, getState());
  enterRule(_localctx, 4, NodeLangParser::RuleFuncDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(25);
    match(NodeLangParser::ID);
    setState(26);
    match(NodeLangParser::T__0);
    setState(30);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == NodeLangParser::ID) {
      setState(27);
      match(NodeLangParser::ID);
      setState(32);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(33);
    match(NodeLangParser::T__2);
    setState(35); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(34);
      node();
      setState(37); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1010) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NodeContext ------------------------------------------------------------------

NodeLangParser::NodeContext::NodeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

NodeLangParser::NodeDeclContext* NodeLangParser::NodeContext::nodeDecl() {
  return getRuleContext<NodeLangParser::NodeDeclContext>(0);
}

NodeLangParser::ExprContext* NodeLangParser::NodeContext::expr() {
  return getRuleContext<NodeLangParser::ExprContext>(0);
}

tree::TerminalNode* NodeLangParser::NodeContext::ID() {
  return getToken(NodeLangParser::ID, 0);
}

std::vector<NodeLangParser::NodeContext *> NodeLangParser::NodeContext::node() {
  return getRuleContexts<NodeLangParser::NodeContext>();
}

NodeLangParser::NodeContext* NodeLangParser::NodeContext::node(size_t i) {
  return getRuleContext<NodeLangParser::NodeContext>(i);
}


size_t NodeLangParser::NodeContext::getRuleIndex() const {
  return NodeLangParser::RuleNode;
}

void NodeLangParser::NodeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NodeLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNode(this);
}

void NodeLangParser::NodeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NodeLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNode(this);
}


std::any NodeLangParser::NodeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NodeLangVisitor*>(visitor))
    return parserVisitor->visitNode(this);
  else
    return visitor->visitChildren(this);
}

NodeLangParser::NodeContext* NodeLangParser::node() {
  NodeContext *_localctx = _tracker.createInstance<NodeContext>(_ctx, getState());
  enterRule(_localctx, 6, NodeLangParser::RuleNode);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(50);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(39);
      nodeDecl();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(40);
      expr();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(41);
      match(NodeLangParser::T__0);
      setState(42);
      match(NodeLangParser::ID);
      setState(46);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1010) != 0)) {
        setState(43);
        node();
        setState(48);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(49);
      match(NodeLangParser::T__2);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

NodeLangParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NodeLangParser::VarDeclContext::ID() {
  return getToken(NodeLangParser::ID, 0);
}

NodeLangParser::ExprContext* NodeLangParser::VarDeclContext::expr() {
  return getRuleContext<NodeLangParser::ExprContext>(0);
}


size_t NodeLangParser::VarDeclContext::getRuleIndex() const {
  return NodeLangParser::RuleVarDecl;
}

void NodeLangParser::VarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NodeLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDecl(this);
}

void NodeLangParser::VarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NodeLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDecl(this);
}


std::any NodeLangParser::VarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NodeLangVisitor*>(visitor))
    return parserVisitor->visitVarDecl(this);
  else
    return visitor->visitChildren(this);
}

NodeLangParser::VarDeclContext* NodeLangParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 8, NodeLangParser::RuleVarDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(52);
    match(NodeLangParser::ID);
    setState(53);
    expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

NodeLangParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<NodeLangParser::ExprContext *> NodeLangParser::ExprContext::expr() {
  return getRuleContexts<NodeLangParser::ExprContext>();
}

NodeLangParser::ExprContext* NodeLangParser::ExprContext::expr(size_t i) {
  return getRuleContext<NodeLangParser::ExprContext>(i);
}

tree::TerminalNode* NodeLangParser::ExprContext::INT() {
  return getToken(NodeLangParser::INT, 0);
}

tree::TerminalNode* NodeLangParser::ExprContext::ID() {
  return getToken(NodeLangParser::ID, 0);
}


size_t NodeLangParser::ExprContext::getRuleIndex() const {
  return NodeLangParser::RuleExpr;
}

void NodeLangParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NodeLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void NodeLangParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NodeLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


std::any NodeLangParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NodeLangVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

NodeLangParser::ExprContext* NodeLangParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 10, NodeLangParser::RuleExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(71);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(55);
      match(NodeLangParser::T__3);
      setState(56);
      expr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(57);
      _la = _input->LA(1);
      if (!(_la == NodeLangParser::T__4

      || _la == NodeLangParser::T__5)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(58);
      expr();
      setState(59);
      expr();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(61);
      _la = _input->LA(1);
      if (!(_la == NodeLangParser::T__3

      || _la == NodeLangParser::T__6)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(62);
      expr();
      setState(63);
      expr();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(65);
      match(NodeLangParser::T__0);
      setState(66);
      expr();
      setState(67);
      match(NodeLangParser::T__2);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(69);
      match(NodeLangParser::INT);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(70);
      match(NodeLangParser::ID);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void NodeLangParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  nodelangParserInitialize();
#else
  ::antlr4::internal::call_once(nodelangParserOnceFlag, nodelangParserInitialize);
#endif
}
