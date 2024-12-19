
// Generated from Forge.g4 by ANTLR 4.13.0


#include "ForgeListener.h"
#include "ForgeVisitor.h"

#include "ForgeParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct ForgeParserStaticData final {
  ForgeParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ForgeParserStaticData(const ForgeParserStaticData&) = delete;
  ForgeParserStaticData(ForgeParserStaticData&&) = delete;
  ForgeParserStaticData& operator=(const ForgeParserStaticData&) = delete;
  ForgeParserStaticData& operator=(ForgeParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag forgeParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
ForgeParserStaticData *forgeParserStaticData = nullptr;

void forgeParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (forgeParserStaticData != nullptr) {
    return;
  }
#else
  assert(forgeParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<ForgeParserStaticData>(
    std::vector<std::string>{
      "program", "block", "setBColor", "varDecl", "randGet", "ascendLoop", 
      "iterLoop", "gradLoop", "xLoop", "yLoop", "descendLoop", "expr"
    },
    std::vector<std::string>{
      "", "'based'", "'color'", "'is'", "'let'", "'rand'", "'ascend'", "'['", 
      "']'", "'iterator'", "'gradient'", "'xpoint'", "'ypoint'", "'descend'", 
      "'-'", "'*'", "'/'", "'+'", "'{'", "'}'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "NAME", "INT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,22,119,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,1,0,4,0,26,8,0,11,0,12,0,27,
  	1,1,1,1,1,1,5,1,33,8,1,10,1,12,1,36,9,1,1,1,5,1,39,8,1,10,1,12,1,42,9,
  	1,1,1,5,1,45,8,1,10,1,12,1,48,9,1,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,
  	1,3,3,3,60,8,3,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,
  	6,1,6,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,10,1,10,1,10,
  	1,10,1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	3,11,106,8,11,1,11,1,11,1,11,1,11,1,11,1,11,5,11,114,8,11,10,11,12,11,
  	117,9,11,1,11,0,1,22,12,0,2,4,6,8,10,12,14,16,18,20,22,0,3,1,0,20,21,
  	1,0,15,16,2,0,14,14,17,17,116,0,25,1,0,0,0,2,29,1,0,0,0,4,49,1,0,0,0,
  	6,54,1,0,0,0,8,61,1,0,0,0,10,64,1,0,0,0,12,72,1,0,0,0,14,76,1,0,0,0,16,
  	80,1,0,0,0,18,84,1,0,0,0,20,88,1,0,0,0,22,105,1,0,0,0,24,26,3,2,1,0,25,
  	24,1,0,0,0,26,27,1,0,0,0,27,25,1,0,0,0,27,28,1,0,0,0,28,1,1,0,0,0,29,
  	30,5,20,0,0,30,34,3,4,2,0,31,33,3,6,3,0,32,31,1,0,0,0,33,36,1,0,0,0,34,
  	32,1,0,0,0,34,35,1,0,0,0,35,40,1,0,0,0,36,34,1,0,0,0,37,39,3,10,5,0,38,
  	37,1,0,0,0,39,42,1,0,0,0,40,38,1,0,0,0,40,41,1,0,0,0,41,46,1,0,0,0,42,
  	40,1,0,0,0,43,45,3,20,10,0,44,43,1,0,0,0,45,48,1,0,0,0,46,44,1,0,0,0,
  	46,47,1,0,0,0,47,3,1,0,0,0,48,46,1,0,0,0,49,50,5,1,0,0,50,51,5,2,0,0,
  	51,52,5,3,0,0,52,53,5,21,0,0,53,5,1,0,0,0,54,55,5,4,0,0,55,56,5,20,0,
  	0,56,59,5,3,0,0,57,60,5,21,0,0,58,60,3,8,4,0,59,57,1,0,0,0,59,58,1,0,
  	0,0,60,7,1,0,0,0,61,62,5,5,0,0,62,63,5,21,0,0,63,9,1,0,0,0,64,65,5,6,
  	0,0,65,66,5,7,0,0,66,67,3,12,6,0,67,68,3,14,7,0,68,69,3,16,8,0,69,70,
  	3,18,9,0,70,71,5,8,0,0,71,11,1,0,0,0,72,73,5,9,0,0,73,74,5,3,0,0,74,75,
  	7,0,0,0,75,13,1,0,0,0,76,77,5,10,0,0,77,78,5,3,0,0,78,79,5,20,0,0,79,
  	15,1,0,0,0,80,81,5,11,0,0,81,82,5,3,0,0,82,83,5,20,0,0,83,17,1,0,0,0,
  	84,85,5,12,0,0,85,86,5,3,0,0,86,87,5,20,0,0,87,19,1,0,0,0,88,89,5,13,
  	0,0,89,90,5,7,0,0,90,91,3,12,6,0,91,92,3,14,7,0,92,93,3,16,8,0,93,94,
  	3,18,9,0,94,95,5,8,0,0,95,21,1,0,0,0,96,97,6,11,-1,0,97,98,5,14,0,0,98,
  	106,3,22,11,6,99,100,5,18,0,0,100,101,3,22,11,0,101,102,5,19,0,0,102,
  	106,1,0,0,0,103,106,5,21,0,0,104,106,5,20,0,0,105,96,1,0,0,0,105,99,1,
  	0,0,0,105,103,1,0,0,0,105,104,1,0,0,0,106,115,1,0,0,0,107,108,10,5,0,
  	0,108,109,7,1,0,0,109,114,3,22,11,6,110,111,10,4,0,0,111,112,7,2,0,0,
  	112,114,3,22,11,5,113,107,1,0,0,0,113,110,1,0,0,0,114,117,1,0,0,0,115,
  	113,1,0,0,0,115,116,1,0,0,0,116,23,1,0,0,0,117,115,1,0,0,0,8,27,34,40,
  	46,59,105,113,115
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  forgeParserStaticData = staticData.release();
}

}

ForgeParser::ForgeParser(TokenStream *input) : ForgeParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

ForgeParser::ForgeParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  ForgeParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *forgeParserStaticData->atn, forgeParserStaticData->decisionToDFA, forgeParserStaticData->sharedContextCache, options);
}

ForgeParser::~ForgeParser() {
  delete _interpreter;
}

const atn::ATN& ForgeParser::getATN() const {
  return *forgeParserStaticData->atn;
}

std::string ForgeParser::getGrammarFileName() const {
  return "Forge.g4";
}

const std::vector<std::string>& ForgeParser::getRuleNames() const {
  return forgeParserStaticData->ruleNames;
}

const dfa::Vocabulary& ForgeParser::getVocabulary() const {
  return forgeParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ForgeParser::getSerializedATN() const {
  return forgeParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

ForgeParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ForgeParser::BlockContext *> ForgeParser::ProgramContext::block() {
  return getRuleContexts<ForgeParser::BlockContext>();
}

ForgeParser::BlockContext* ForgeParser::ProgramContext::block(size_t i) {
  return getRuleContext<ForgeParser::BlockContext>(i);
}


size_t ForgeParser::ProgramContext::getRuleIndex() const {
  return ForgeParser::RuleProgram;
}

void ForgeParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ForgeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void ForgeParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ForgeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any ForgeParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ForgeVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

ForgeParser::ProgramContext* ForgeParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, ForgeParser::RuleProgram);
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
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(24);
      block();
      setState(27); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == ForgeParser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

ForgeParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ForgeParser::BlockContext::NAME() {
  return getToken(ForgeParser::NAME, 0);
}

ForgeParser::SetBColorContext* ForgeParser::BlockContext::setBColor() {
  return getRuleContext<ForgeParser::SetBColorContext>(0);
}

std::vector<ForgeParser::VarDeclContext *> ForgeParser::BlockContext::varDecl() {
  return getRuleContexts<ForgeParser::VarDeclContext>();
}

ForgeParser::VarDeclContext* ForgeParser::BlockContext::varDecl(size_t i) {
  return getRuleContext<ForgeParser::VarDeclContext>(i);
}

std::vector<ForgeParser::AscendLoopContext *> ForgeParser::BlockContext::ascendLoop() {
  return getRuleContexts<ForgeParser::AscendLoopContext>();
}

ForgeParser::AscendLoopContext* ForgeParser::BlockContext::ascendLoop(size_t i) {
  return getRuleContext<ForgeParser::AscendLoopContext>(i);
}

std::vector<ForgeParser::DescendLoopContext *> ForgeParser::BlockContext::descendLoop() {
  return getRuleContexts<ForgeParser::DescendLoopContext>();
}

ForgeParser::DescendLoopContext* ForgeParser::BlockContext::descendLoop(size_t i) {
  return getRuleContext<ForgeParser::DescendLoopContext>(i);
}


size_t ForgeParser::BlockContext::getRuleIndex() const {
  return ForgeParser::RuleBlock;
}

void ForgeParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ForgeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void ForgeParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ForgeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


std::any ForgeParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ForgeVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

ForgeParser::BlockContext* ForgeParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 2, ForgeParser::RuleBlock);
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
    setState(29);
    match(ForgeParser::NAME);
    setState(30);
    setBColor();
    setState(34);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ForgeParser::T__3) {
      setState(31);
      varDecl();
      setState(36);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(40);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ForgeParser::T__5) {
      setState(37);
      ascendLoop();
      setState(42);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(46);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ForgeParser::T__12) {
      setState(43);
      descendLoop();
      setState(48);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetBColorContext ------------------------------------------------------------------

ForgeParser::SetBColorContext::SetBColorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ForgeParser::SetBColorContext::INT() {
  return getToken(ForgeParser::INT, 0);
}


size_t ForgeParser::SetBColorContext::getRuleIndex() const {
  return ForgeParser::RuleSetBColor;
}

void ForgeParser::SetBColorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ForgeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSetBColor(this);
}

void ForgeParser::SetBColorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ForgeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSetBColor(this);
}


std::any ForgeParser::SetBColorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ForgeVisitor*>(visitor))
    return parserVisitor->visitSetBColor(this);
  else
    return visitor->visitChildren(this);
}

ForgeParser::SetBColorContext* ForgeParser::setBColor() {
  SetBColorContext *_localctx = _tracker.createInstance<SetBColorContext>(_ctx, getState());
  enterRule(_localctx, 4, ForgeParser::RuleSetBColor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(49);
    match(ForgeParser::T__0);
    setState(50);
    match(ForgeParser::T__1);
    setState(51);
    match(ForgeParser::T__2);
    setState(52);
    match(ForgeParser::INT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

ForgeParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ForgeParser::VarDeclContext::NAME() {
  return getToken(ForgeParser::NAME, 0);
}

tree::TerminalNode* ForgeParser::VarDeclContext::INT() {
  return getToken(ForgeParser::INT, 0);
}

ForgeParser::RandGetContext* ForgeParser::VarDeclContext::randGet() {
  return getRuleContext<ForgeParser::RandGetContext>(0);
}


size_t ForgeParser::VarDeclContext::getRuleIndex() const {
  return ForgeParser::RuleVarDecl;
}

void ForgeParser::VarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ForgeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDecl(this);
}

void ForgeParser::VarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ForgeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDecl(this);
}


std::any ForgeParser::VarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ForgeVisitor*>(visitor))
    return parserVisitor->visitVarDecl(this);
  else
    return visitor->visitChildren(this);
}

ForgeParser::VarDeclContext* ForgeParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 6, ForgeParser::RuleVarDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(54);
    match(ForgeParser::T__3);
    setState(55);
    match(ForgeParser::NAME);
    setState(56);
    match(ForgeParser::T__2);
    setState(59);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ForgeParser::INT: {
        setState(57);
        match(ForgeParser::INT);
        break;
      }

      case ForgeParser::T__4: {
        setState(58);
        randGet();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RandGetContext ------------------------------------------------------------------

ForgeParser::RandGetContext::RandGetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ForgeParser::RandGetContext::INT() {
  return getToken(ForgeParser::INT, 0);
}


size_t ForgeParser::RandGetContext::getRuleIndex() const {
  return ForgeParser::RuleRandGet;
}

void ForgeParser::RandGetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ForgeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRandGet(this);
}

void ForgeParser::RandGetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ForgeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRandGet(this);
}


std::any ForgeParser::RandGetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ForgeVisitor*>(visitor))
    return parserVisitor->visitRandGet(this);
  else
    return visitor->visitChildren(this);
}

ForgeParser::RandGetContext* ForgeParser::randGet() {
  RandGetContext *_localctx = _tracker.createInstance<RandGetContext>(_ctx, getState());
  enterRule(_localctx, 8, ForgeParser::RuleRandGet);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(61);
    match(ForgeParser::T__4);
    setState(62);
    match(ForgeParser::INT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AscendLoopContext ------------------------------------------------------------------

ForgeParser::AscendLoopContext::AscendLoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ForgeParser::IterLoopContext* ForgeParser::AscendLoopContext::iterLoop() {
  return getRuleContext<ForgeParser::IterLoopContext>(0);
}

ForgeParser::GradLoopContext* ForgeParser::AscendLoopContext::gradLoop() {
  return getRuleContext<ForgeParser::GradLoopContext>(0);
}

ForgeParser::XLoopContext* ForgeParser::AscendLoopContext::xLoop() {
  return getRuleContext<ForgeParser::XLoopContext>(0);
}

ForgeParser::YLoopContext* ForgeParser::AscendLoopContext::yLoop() {
  return getRuleContext<ForgeParser::YLoopContext>(0);
}


size_t ForgeParser::AscendLoopContext::getRuleIndex() const {
  return ForgeParser::RuleAscendLoop;
}

void ForgeParser::AscendLoopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ForgeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAscendLoop(this);
}

void ForgeParser::AscendLoopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ForgeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAscendLoop(this);
}


std::any ForgeParser::AscendLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ForgeVisitor*>(visitor))
    return parserVisitor->visitAscendLoop(this);
  else
    return visitor->visitChildren(this);
}

ForgeParser::AscendLoopContext* ForgeParser::ascendLoop() {
  AscendLoopContext *_localctx = _tracker.createInstance<AscendLoopContext>(_ctx, getState());
  enterRule(_localctx, 10, ForgeParser::RuleAscendLoop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(64);
    match(ForgeParser::T__5);
    setState(65);
    match(ForgeParser::T__6);
    setState(66);
    iterLoop();
    setState(67);
    gradLoop();
    setState(68);
    xLoop();
    setState(69);
    yLoop();
    setState(70);
    match(ForgeParser::T__7);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IterLoopContext ------------------------------------------------------------------

ForgeParser::IterLoopContext::IterLoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ForgeParser::IterLoopContext::NAME() {
  return getToken(ForgeParser::NAME, 0);
}

tree::TerminalNode* ForgeParser::IterLoopContext::INT() {
  return getToken(ForgeParser::INT, 0);
}


size_t ForgeParser::IterLoopContext::getRuleIndex() const {
  return ForgeParser::RuleIterLoop;
}

void ForgeParser::IterLoopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ForgeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIterLoop(this);
}

void ForgeParser::IterLoopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ForgeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIterLoop(this);
}


std::any ForgeParser::IterLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ForgeVisitor*>(visitor))
    return parserVisitor->visitIterLoop(this);
  else
    return visitor->visitChildren(this);
}

ForgeParser::IterLoopContext* ForgeParser::iterLoop() {
  IterLoopContext *_localctx = _tracker.createInstance<IterLoopContext>(_ctx, getState());
  enterRule(_localctx, 12, ForgeParser::RuleIterLoop);
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
    setState(72);
    match(ForgeParser::T__8);
    setState(73);
    match(ForgeParser::T__2);
    setState(74);
    _la = _input->LA(1);
    if (!(_la == ForgeParser::NAME

    || _la == ForgeParser::INT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GradLoopContext ------------------------------------------------------------------

ForgeParser::GradLoopContext::GradLoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ForgeParser::GradLoopContext::NAME() {
  return getToken(ForgeParser::NAME, 0);
}


size_t ForgeParser::GradLoopContext::getRuleIndex() const {
  return ForgeParser::RuleGradLoop;
}

void ForgeParser::GradLoopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ForgeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGradLoop(this);
}

void ForgeParser::GradLoopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ForgeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGradLoop(this);
}


std::any ForgeParser::GradLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ForgeVisitor*>(visitor))
    return parserVisitor->visitGradLoop(this);
  else
    return visitor->visitChildren(this);
}

ForgeParser::GradLoopContext* ForgeParser::gradLoop() {
  GradLoopContext *_localctx = _tracker.createInstance<GradLoopContext>(_ctx, getState());
  enterRule(_localctx, 14, ForgeParser::RuleGradLoop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(76);
    match(ForgeParser::T__9);
    setState(77);
    match(ForgeParser::T__2);
    setState(78);
    match(ForgeParser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- XLoopContext ------------------------------------------------------------------

ForgeParser::XLoopContext::XLoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ForgeParser::XLoopContext::NAME() {
  return getToken(ForgeParser::NAME, 0);
}


size_t ForgeParser::XLoopContext::getRuleIndex() const {
  return ForgeParser::RuleXLoop;
}

void ForgeParser::XLoopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ForgeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterXLoop(this);
}

void ForgeParser::XLoopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ForgeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitXLoop(this);
}


std::any ForgeParser::XLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ForgeVisitor*>(visitor))
    return parserVisitor->visitXLoop(this);
  else
    return visitor->visitChildren(this);
}

ForgeParser::XLoopContext* ForgeParser::xLoop() {
  XLoopContext *_localctx = _tracker.createInstance<XLoopContext>(_ctx, getState());
  enterRule(_localctx, 16, ForgeParser::RuleXLoop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(80);
    match(ForgeParser::T__10);
    setState(81);
    match(ForgeParser::T__2);
    setState(82);
    match(ForgeParser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- YLoopContext ------------------------------------------------------------------

ForgeParser::YLoopContext::YLoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ForgeParser::YLoopContext::NAME() {
  return getToken(ForgeParser::NAME, 0);
}


size_t ForgeParser::YLoopContext::getRuleIndex() const {
  return ForgeParser::RuleYLoop;
}

void ForgeParser::YLoopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ForgeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterYLoop(this);
}

void ForgeParser::YLoopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ForgeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitYLoop(this);
}


std::any ForgeParser::YLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ForgeVisitor*>(visitor))
    return parserVisitor->visitYLoop(this);
  else
    return visitor->visitChildren(this);
}

ForgeParser::YLoopContext* ForgeParser::yLoop() {
  YLoopContext *_localctx = _tracker.createInstance<YLoopContext>(_ctx, getState());
  enterRule(_localctx, 18, ForgeParser::RuleYLoop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(84);
    match(ForgeParser::T__11);
    setState(85);
    match(ForgeParser::T__2);
    setState(86);
    match(ForgeParser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DescendLoopContext ------------------------------------------------------------------

ForgeParser::DescendLoopContext::DescendLoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ForgeParser::IterLoopContext* ForgeParser::DescendLoopContext::iterLoop() {
  return getRuleContext<ForgeParser::IterLoopContext>(0);
}

ForgeParser::GradLoopContext* ForgeParser::DescendLoopContext::gradLoop() {
  return getRuleContext<ForgeParser::GradLoopContext>(0);
}

ForgeParser::XLoopContext* ForgeParser::DescendLoopContext::xLoop() {
  return getRuleContext<ForgeParser::XLoopContext>(0);
}

ForgeParser::YLoopContext* ForgeParser::DescendLoopContext::yLoop() {
  return getRuleContext<ForgeParser::YLoopContext>(0);
}


size_t ForgeParser::DescendLoopContext::getRuleIndex() const {
  return ForgeParser::RuleDescendLoop;
}

void ForgeParser::DescendLoopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ForgeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDescendLoop(this);
}

void ForgeParser::DescendLoopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ForgeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDescendLoop(this);
}


std::any ForgeParser::DescendLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ForgeVisitor*>(visitor))
    return parserVisitor->visitDescendLoop(this);
  else
    return visitor->visitChildren(this);
}

ForgeParser::DescendLoopContext* ForgeParser::descendLoop() {
  DescendLoopContext *_localctx = _tracker.createInstance<DescendLoopContext>(_ctx, getState());
  enterRule(_localctx, 20, ForgeParser::RuleDescendLoop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(88);
    match(ForgeParser::T__12);
    setState(89);
    match(ForgeParser::T__6);
    setState(90);
    iterLoop();
    setState(91);
    gradLoop();
    setState(92);
    xLoop();
    setState(93);
    yLoop();
    setState(94);
    match(ForgeParser::T__7);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

ForgeParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ForgeParser::ExprContext *> ForgeParser::ExprContext::expr() {
  return getRuleContexts<ForgeParser::ExprContext>();
}

ForgeParser::ExprContext* ForgeParser::ExprContext::expr(size_t i) {
  return getRuleContext<ForgeParser::ExprContext>(i);
}

tree::TerminalNode* ForgeParser::ExprContext::INT() {
  return getToken(ForgeParser::INT, 0);
}

tree::TerminalNode* ForgeParser::ExprContext::NAME() {
  return getToken(ForgeParser::NAME, 0);
}


size_t ForgeParser::ExprContext::getRuleIndex() const {
  return ForgeParser::RuleExpr;
}

void ForgeParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ForgeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void ForgeParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ForgeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


std::any ForgeParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ForgeVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}


ForgeParser::ExprContext* ForgeParser::expr() {
   return expr(0);
}

ForgeParser::ExprContext* ForgeParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ForgeParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  ForgeParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, ForgeParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(105);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ForgeParser::T__13: {
        setState(97);
        match(ForgeParser::T__13);
        setState(98);
        expr(6);
        break;
      }

      case ForgeParser::T__17: {
        setState(99);
        match(ForgeParser::T__17);
        setState(100);
        expr(0);
        setState(101);
        match(ForgeParser::T__18);
        break;
      }

      case ForgeParser::INT: {
        setState(103);
        match(ForgeParser::INT);
        break;
      }

      case ForgeParser::NAME: {
        setState(104);
        match(ForgeParser::NAME);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(115);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(113);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(107);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(108);
          _la = _input->LA(1);
          if (!(_la == ForgeParser::T__14

          || _la == ForgeParser::T__15)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(109);
          expr(6);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(110);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(111);
          _la = _input->LA(1);
          if (!(_la == ForgeParser::T__13

          || _la == ForgeParser::T__16)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(112);
          expr(5);
          break;
        }

        default:
          break;
        } 
      }
      setState(117);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool ForgeParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 11: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ForgeParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 5);
    case 1: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

void ForgeParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  forgeParserInitialize();
#else
  ::antlr4::internal::call_once(forgeParserOnceFlag, forgeParserInitialize);
#endif
}
