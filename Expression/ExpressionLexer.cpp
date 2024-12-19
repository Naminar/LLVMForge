
// Generated from Expression.g4 by ANTLR 4.13.0


#include "ExpressionLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct ExpressionLexerStaticData final {
  ExpressionLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ExpressionLexerStaticData(const ExpressionLexerStaticData&) = delete;
  ExpressionLexerStaticData(ExpressionLexerStaticData&&) = delete;
  ExpressionLexerStaticData& operator=(const ExpressionLexerStaticData&) = delete;
  ExpressionLexerStaticData& operator=(ExpressionLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag expressionlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
ExpressionLexerStaticData *expressionlexerLexerStaticData = nullptr;

void expressionlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (expressionlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(expressionlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<ExpressionLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "INT", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'-'", "'*'", "'/'", "'+'", "'{'", "'}'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "INT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,8,41,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,
  	2,7,7,7,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,4,6,31,8,
  	6,11,6,12,6,32,1,7,4,7,36,8,7,11,7,12,7,37,1,7,1,7,0,0,8,1,1,3,2,5,3,
  	7,4,9,5,11,6,13,7,15,8,1,0,2,1,0,48,57,3,0,9,10,13,13,32,32,42,0,1,1,
  	0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,
  	13,1,0,0,0,0,15,1,0,0,0,1,17,1,0,0,0,3,19,1,0,0,0,5,21,1,0,0,0,7,23,1,
  	0,0,0,9,25,1,0,0,0,11,27,1,0,0,0,13,30,1,0,0,0,15,35,1,0,0,0,17,18,5,
  	45,0,0,18,2,1,0,0,0,19,20,5,42,0,0,20,4,1,0,0,0,21,22,5,47,0,0,22,6,1,
  	0,0,0,23,24,5,43,0,0,24,8,1,0,0,0,25,26,5,123,0,0,26,10,1,0,0,0,27,28,
  	5,125,0,0,28,12,1,0,0,0,29,31,7,0,0,0,30,29,1,0,0,0,31,32,1,0,0,0,32,
  	30,1,0,0,0,32,33,1,0,0,0,33,14,1,0,0,0,34,36,7,1,0,0,35,34,1,0,0,0,36,
  	37,1,0,0,0,37,35,1,0,0,0,37,38,1,0,0,0,38,39,1,0,0,0,39,40,6,7,0,0,40,
  	16,1,0,0,0,3,0,32,37,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  expressionlexerLexerStaticData = staticData.release();
}

}

ExpressionLexer::ExpressionLexer(CharStream *input) : Lexer(input) {
  ExpressionLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *expressionlexerLexerStaticData->atn, expressionlexerLexerStaticData->decisionToDFA, expressionlexerLexerStaticData->sharedContextCache);
}

ExpressionLexer::~ExpressionLexer() {
  delete _interpreter;
}

std::string ExpressionLexer::getGrammarFileName() const {
  return "Expression.g4";
}

const std::vector<std::string>& ExpressionLexer::getRuleNames() const {
  return expressionlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& ExpressionLexer::getChannelNames() const {
  return expressionlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& ExpressionLexer::getModeNames() const {
  return expressionlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& ExpressionLexer::getVocabulary() const {
  return expressionlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ExpressionLexer::getSerializedATN() const {
  return expressionlexerLexerStaticData->serializedATN;
}

const atn::ATN& ExpressionLexer::getATN() const {
  return *expressionlexerLexerStaticData->atn;
}




void ExpressionLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  expressionlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(expressionlexerLexerOnceFlag, expressionlexerLexerInitialize);
#endif
}
