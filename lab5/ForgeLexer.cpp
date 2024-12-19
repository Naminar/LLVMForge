
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
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "T__9", "T__10", "T__11", "T__12", "T__13", "T__14", "T__15", "T__16", 
      "T__17", "T__18", "NAME", "INT", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'based'", "'color'", "'is'", "'let'", "'rand'", "'ascend'", "'['", 
      "']'", "'iterator'", "'gradient'", "'xpoint'", "'ypoint'", "'descend'", 
      "'-'", "'*'", "'/'", "'+'", "'('", "')'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "NAME", "INT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,22,149,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,3,
  	1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,
  	7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,
  	1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,
  	11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,14,1,14,1,
  	15,1,15,1,16,1,16,1,17,1,17,1,18,1,18,1,19,4,19,134,8,19,11,19,12,19,
  	135,1,20,4,20,139,8,20,11,20,12,20,140,1,21,4,21,144,8,21,11,21,12,21,
  	145,1,21,1,21,0,0,22,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,
  	11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,
  	1,0,3,3,0,65,90,95,95,97,122,1,0,48,57,3,0,9,10,13,13,32,32,151,0,1,1,
  	0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,
  	13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,
  	0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,
  	0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,1,
  	45,1,0,0,0,3,51,1,0,0,0,5,57,1,0,0,0,7,60,1,0,0,0,9,64,1,0,0,0,11,69,
  	1,0,0,0,13,76,1,0,0,0,15,78,1,0,0,0,17,80,1,0,0,0,19,89,1,0,0,0,21,98,
  	1,0,0,0,23,105,1,0,0,0,25,112,1,0,0,0,27,120,1,0,0,0,29,122,1,0,0,0,31,
  	124,1,0,0,0,33,126,1,0,0,0,35,128,1,0,0,0,37,130,1,0,0,0,39,133,1,0,0,
  	0,41,138,1,0,0,0,43,143,1,0,0,0,45,46,5,98,0,0,46,47,5,97,0,0,47,48,5,
  	115,0,0,48,49,5,101,0,0,49,50,5,100,0,0,50,2,1,0,0,0,51,52,5,99,0,0,52,
  	53,5,111,0,0,53,54,5,108,0,0,54,55,5,111,0,0,55,56,5,114,0,0,56,4,1,0,
  	0,0,57,58,5,105,0,0,58,59,5,115,0,0,59,6,1,0,0,0,60,61,5,108,0,0,61,62,
  	5,101,0,0,62,63,5,116,0,0,63,8,1,0,0,0,64,65,5,114,0,0,65,66,5,97,0,0,
  	66,67,5,110,0,0,67,68,5,100,0,0,68,10,1,0,0,0,69,70,5,97,0,0,70,71,5,
  	115,0,0,71,72,5,99,0,0,72,73,5,101,0,0,73,74,5,110,0,0,74,75,5,100,0,
  	0,75,12,1,0,0,0,76,77,5,91,0,0,77,14,1,0,0,0,78,79,5,93,0,0,79,16,1,0,
  	0,0,80,81,5,105,0,0,81,82,5,116,0,0,82,83,5,101,0,0,83,84,5,114,0,0,84,
  	85,5,97,0,0,85,86,5,116,0,0,86,87,5,111,0,0,87,88,5,114,0,0,88,18,1,0,
  	0,0,89,90,5,103,0,0,90,91,5,114,0,0,91,92,5,97,0,0,92,93,5,100,0,0,93,
  	94,5,105,0,0,94,95,5,101,0,0,95,96,5,110,0,0,96,97,5,116,0,0,97,20,1,
  	0,0,0,98,99,5,120,0,0,99,100,5,112,0,0,100,101,5,111,0,0,101,102,5,105,
  	0,0,102,103,5,110,0,0,103,104,5,116,0,0,104,22,1,0,0,0,105,106,5,121,
  	0,0,106,107,5,112,0,0,107,108,5,111,0,0,108,109,5,105,0,0,109,110,5,110,
  	0,0,110,111,5,116,0,0,111,24,1,0,0,0,112,113,5,100,0,0,113,114,5,101,
  	0,0,114,115,5,115,0,0,115,116,5,99,0,0,116,117,5,101,0,0,117,118,5,110,
  	0,0,118,119,5,100,0,0,119,26,1,0,0,0,120,121,5,45,0,0,121,28,1,0,0,0,
  	122,123,5,42,0,0,123,30,1,0,0,0,124,125,5,47,0,0,125,32,1,0,0,0,126,127,
  	5,43,0,0,127,34,1,0,0,0,128,129,5,40,0,0,129,36,1,0,0,0,130,131,5,41,
  	0,0,131,38,1,0,0,0,132,134,7,0,0,0,133,132,1,0,0,0,134,135,1,0,0,0,135,
  	133,1,0,0,0,135,136,1,0,0,0,136,40,1,0,0,0,137,139,7,1,0,0,138,137,1,
  	0,0,0,139,140,1,0,0,0,140,138,1,0,0,0,140,141,1,0,0,0,141,42,1,0,0,0,
  	142,144,7,2,0,0,143,142,1,0,0,0,144,145,1,0,0,0,145,143,1,0,0,0,145,146,
  	1,0,0,0,146,147,1,0,0,0,147,148,6,21,0,0,148,44,1,0,0,0,4,0,135,140,145,
  	1,6,0,0
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
