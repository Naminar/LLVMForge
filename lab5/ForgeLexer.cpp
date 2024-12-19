
// Generated from Forge.g4 by ANTLR 4.13.0


#include "ForgeLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct ForgeLexerStaticData final {
  ForgeLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ForgeLexerStaticData(const ForgeLexerStaticData&) = delete;
  ForgeLexerStaticData(ForgeLexerStaticData&&) = delete;
  ForgeLexerStaticData& operator=(const ForgeLexerStaticData&) = delete;
  ForgeLexerStaticData& operator=(ForgeLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag forgelexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
ForgeLexerStaticData *forgelexerLexerStaticData = nullptr;

void forgelexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (forgelexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(forgelexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<ForgeLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "NAME", "INT", "WS"
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
      "", "", "", "", "", "", "", "NAME", "INT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,9,48,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,
  	2,7,7,7,2,8,7,8,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,4,
  	6,33,8,6,11,6,12,6,34,1,7,4,7,38,8,7,11,7,12,7,39,1,8,4,8,43,8,8,11,8,
  	12,8,44,1,8,1,8,0,0,9,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,1,0,3,3,
  	0,65,90,95,95,97,122,1,0,48,57,3,0,9,10,13,13,32,32,50,0,1,1,0,0,0,0,
  	3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,
  	0,0,15,1,0,0,0,0,17,1,0,0,0,1,19,1,0,0,0,3,21,1,0,0,0,5,23,1,0,0,0,7,
  	25,1,0,0,0,9,27,1,0,0,0,11,29,1,0,0,0,13,32,1,0,0,0,15,37,1,0,0,0,17,
  	42,1,0,0,0,19,20,5,45,0,0,20,2,1,0,0,0,21,22,5,42,0,0,22,4,1,0,0,0,23,
  	24,5,47,0,0,24,6,1,0,0,0,25,26,5,43,0,0,26,8,1,0,0,0,27,28,5,123,0,0,
  	28,10,1,0,0,0,29,30,5,125,0,0,30,12,1,0,0,0,31,33,7,0,0,0,32,31,1,0,0,
  	0,33,34,1,0,0,0,34,32,1,0,0,0,34,35,1,0,0,0,35,14,1,0,0,0,36,38,7,1,0,
  	0,37,36,1,0,0,0,38,39,1,0,0,0,39,37,1,0,0,0,39,40,1,0,0,0,40,16,1,0,0,
  	0,41,43,7,2,0,0,42,41,1,0,0,0,43,44,1,0,0,0,44,42,1,0,0,0,44,45,1,0,0,
  	0,45,46,1,0,0,0,46,47,6,8,0,0,47,18,1,0,0,0,4,0,34,39,44,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  forgelexerLexerStaticData = staticData.release();
}

}

ForgeLexer::ForgeLexer(CharStream *input) : Lexer(input) {
  ForgeLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *forgelexerLexerStaticData->atn, forgelexerLexerStaticData->decisionToDFA, forgelexerLexerStaticData->sharedContextCache);
}

ForgeLexer::~ForgeLexer() {
  delete _interpreter;
}

std::string ForgeLexer::getGrammarFileName() const {
  return "Forge.g4";
}

const std::vector<std::string>& ForgeLexer::getRuleNames() const {
  return forgelexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& ForgeLexer::getChannelNames() const {
  return forgelexerLexerStaticData->channelNames;
}

const std::vector<std::string>& ForgeLexer::getModeNames() const {
  return forgelexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& ForgeLexer::getVocabulary() const {
  return forgelexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ForgeLexer::getSerializedATN() const {
  return forgelexerLexerStaticData->serializedATN;
}

const atn::ATN& ForgeLexer::getATN() const {
  return *forgelexerLexerStaticData->atn;
}




void ForgeLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  forgelexerLexerInitialize();
#else
  ::antlr4::internal::call_once(forgelexerLexerOnceFlag, forgelexerLexerInitialize);
#endif
}
