
// Generated from NodeLang.g4 by ANTLR 4.13.0


#include "NodeLangLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct NodeLangLexerStaticData final {
  NodeLangLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  NodeLangLexerStaticData(const NodeLangLexerStaticData&) = delete;
  NodeLangLexerStaticData(NodeLangLexerStaticData&&) = delete;
  NodeLangLexerStaticData& operator=(const NodeLangLexerStaticData&) = delete;
  NodeLangLexerStaticData& operator=(NodeLangLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag nodelanglexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
NodeLangLexerStaticData *nodelanglexerLexerStaticData = nullptr;

void nodelanglexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (nodelanglexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(nodelanglexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<NodeLangLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "ID", "INT", 
      "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'('", "'NODE'", "')'", "'-'", "'*'", "'/'", "'+'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "ID", "INT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,10,55,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,3,1,3,
  	1,4,1,4,1,5,1,5,1,6,1,6,1,7,4,7,40,8,7,11,7,12,7,41,1,8,4,8,45,8,8,11,
  	8,12,8,46,1,9,4,9,50,8,9,11,9,12,9,51,1,9,1,9,0,0,10,1,1,3,2,5,3,7,4,
  	9,5,11,6,13,7,15,8,17,9,19,10,1,0,3,3,0,65,90,95,95,97,122,1,0,48,57,
  	3,0,9,10,13,13,32,32,57,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,
  	0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,
  	1,0,0,0,1,21,1,0,0,0,3,23,1,0,0,0,5,28,1,0,0,0,7,30,1,0,0,0,9,32,1,0,
  	0,0,11,34,1,0,0,0,13,36,1,0,0,0,15,39,1,0,0,0,17,44,1,0,0,0,19,49,1,0,
  	0,0,21,22,5,40,0,0,22,2,1,0,0,0,23,24,5,78,0,0,24,25,5,79,0,0,25,26,5,
  	68,0,0,26,27,5,69,0,0,27,4,1,0,0,0,28,29,5,41,0,0,29,6,1,0,0,0,30,31,
  	5,45,0,0,31,8,1,0,0,0,32,33,5,42,0,0,33,10,1,0,0,0,34,35,5,47,0,0,35,
  	12,1,0,0,0,36,37,5,43,0,0,37,14,1,0,0,0,38,40,7,0,0,0,39,38,1,0,0,0,40,
  	41,1,0,0,0,41,39,1,0,0,0,41,42,1,0,0,0,42,16,1,0,0,0,43,45,7,1,0,0,44,
  	43,1,0,0,0,45,46,1,0,0,0,46,44,1,0,0,0,46,47,1,0,0,0,47,18,1,0,0,0,48,
  	50,7,2,0,0,49,48,1,0,0,0,50,51,1,0,0,0,51,49,1,0,0,0,51,52,1,0,0,0,52,
  	53,1,0,0,0,53,54,6,9,0,0,54,20,1,0,0,0,4,0,41,46,51,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  nodelanglexerLexerStaticData = staticData.release();
}

}

NodeLangLexer::NodeLangLexer(CharStream *input) : Lexer(input) {
  NodeLangLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *nodelanglexerLexerStaticData->atn, nodelanglexerLexerStaticData->decisionToDFA, nodelanglexerLexerStaticData->sharedContextCache);
}

NodeLangLexer::~NodeLangLexer() {
  delete _interpreter;
}

std::string NodeLangLexer::getGrammarFileName() const {
  return "NodeLang.g4";
}

const std::vector<std::string>& NodeLangLexer::getRuleNames() const {
  return nodelanglexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& NodeLangLexer::getChannelNames() const {
  return nodelanglexerLexerStaticData->channelNames;
}

const std::vector<std::string>& NodeLangLexer::getModeNames() const {
  return nodelanglexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& NodeLangLexer::getVocabulary() const {
  return nodelanglexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView NodeLangLexer::getSerializedATN() const {
  return nodelanglexerLexerStaticData->serializedATN;
}

const atn::ATN& NodeLangLexer::getATN() const {
  return *nodelanglexerLexerStaticData->atn;
}




void NodeLangLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  nodelanglexerLexerInitialize();
#else
  ::antlr4::internal::call_once(nodelanglexerLexerOnceFlag, nodelanglexerLexerInitialize);
#endif
}
