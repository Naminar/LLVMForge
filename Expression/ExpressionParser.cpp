
// Generated from Expression.g4 by ANTLR 4.13.0


#include "ExpressionListener.h"
#include "ExpressionVisitor.h"

#include "ExpressionParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct ExpressionParserStaticData final {
  ExpressionParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ExpressionParserStaticData(const ExpressionParserStaticData&) = delete;
  ExpressionParserStaticData(ExpressionParserStaticData&&) = delete;
  ExpressionParserStaticData& operator=(const ExpressionParserStaticData&) = delete;
  ExpressionParserStaticData& operator=(ExpressionParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag expressionParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
ExpressionParserStaticData *expressionParserStaticData = nullptr;

void expressionParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (expressionParserStaticData != nullptr) {
    return;
  }
#else
  assert(expressionParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<ExpressionParserStaticData>(
    std::vector<std::string>{
      "expr"
    },
    std::vector<std::string>{
      "", "'-'", "'*'", "'/'", "'+'", "'{'", "'}'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "INT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,8,24,2,0,7,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,3,0,11,8,0,1,0,1,0,1,
  	0,1,0,1,0,1,0,5,0,19,8,0,10,0,12,0,22,9,0,1,0,0,1,0,1,0,0,2,1,0,2,3,2,
  	0,1,1,4,4,26,0,10,1,0,0,0,2,3,6,0,-1,0,3,4,5,1,0,0,4,11,3,0,0,5,5,6,5,
  	5,0,0,6,7,3,0,0,0,7,8,5,6,0,0,8,11,1,0,0,0,9,11,5,7,0,0,10,2,1,0,0,0,
  	10,5,1,0,0,0,10,9,1,0,0,0,11,20,1,0,0,0,12,13,10,4,0,0,13,14,7,0,0,0,
  	14,19,3,0,0,5,15,16,10,3,0,0,16,17,7,1,0,0,17,19,3,0,0,4,18,12,1,0,0,
  	0,18,15,1,0,0,0,19,22,1,0,0,0,20,18,1,0,0,0,20,21,1,0,0,0,21,1,1,0,0,
  	0,22,20,1,0,0,0,3,10,18,20
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  expressionParserStaticData = staticData.release();
}

}

ExpressionParser::ExpressionParser(TokenStream *input) : ExpressionParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

ExpressionParser::ExpressionParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  ExpressionParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *expressionParserStaticData->atn, expressionParserStaticData->decisionToDFA, expressionParserStaticData->sharedContextCache, options);
}

ExpressionParser::~ExpressionParser() {
  delete _interpreter;
}

const atn::ATN& ExpressionParser::getATN() const {
  return *expressionParserStaticData->atn;
}

std::string ExpressionParser::getGrammarFileName() const {
  return "Expression.g4";
}

const std::vector<std::string>& ExpressionParser::getRuleNames() const {
  return expressionParserStaticData->ruleNames;
}

const dfa::Vocabulary& ExpressionParser::getVocabulary() const {
  return expressionParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ExpressionParser::getSerializedATN() const {
  return expressionParserStaticData->serializedATN;
}


//----------------- ExprContext ------------------------------------------------------------------

ExpressionParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExpressionParser::ExprContext *> ExpressionParser::ExprContext::expr() {
  return getRuleContexts<ExpressionParser::ExprContext>();
}

ExpressionParser::ExprContext* ExpressionParser::ExprContext::expr(size_t i) {
  return getRuleContext<ExpressionParser::ExprContext>(i);
}

tree::TerminalNode* ExpressionParser::ExprContext::INT() {
  return getToken(ExpressionParser::INT, 0);
}


size_t ExpressionParser::ExprContext::getRuleIndex() const {
  return ExpressionParser::RuleExpr;
}

void ExpressionParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExpressionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void ExpressionParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExpressionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


std::any ExpressionParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExpressionVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}


ExpressionParser::ExprContext* ExpressionParser::expr() {
   return expr(0);
}

ExpressionParser::ExprContext* ExpressionParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ExpressionParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  ExpressionParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 0;
  enterRecursionRule(_localctx, 0, ExpressionParser::RuleExpr, precedence);

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
    setState(10);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExpressionParser::T__0: {
        setState(3);
        match(ExpressionParser::T__0);
        setState(4);
        expr(5);
        break;
      }

      case ExpressionParser::T__4: {
        setState(5);
        match(ExpressionParser::T__4);
        setState(6);
        expr(0);
        setState(7);
        match(ExpressionParser::T__5);
        break;
      }

      case ExpressionParser::INT: {
        setState(9);
        match(ExpressionParser::INT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(20);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(18);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(12);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(13);
          _la = _input->LA(1);
          if (!(_la == ExpressionParser::T__1

          || _la == ExpressionParser::T__2)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(14);
          expr(5);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(15);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(16);
          _la = _input->LA(1);
          if (!(_la == ExpressionParser::T__0

          || _la == ExpressionParser::T__3)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(17);
          expr(4);
          break;
        }

        default:
          break;
        } 
      }
      setState(22);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool ExpressionParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 0: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ExpressionParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);
    case 1: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

void ExpressionParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  expressionParserInitialize();
#else
  ::antlr4::internal::call_once(expressionParserOnceFlag, expressionParserInitialize);
#endif
}
