#include "peachyparser.h"

#include "log.h"
#include "token.h"
#include "tokensource.h"

namespace peachy {

  PeachyParser::~PeachyParser() {
    logger->debug("PeachyParser destructor");
  }

  void PeachyParser::parse() {
    logger->debug("PeachyParser::parse()");
    Token * token;
    while(true) {
      try {
        token = tokenSource->nextToken();
      } catch(...) {
        logger->debug("Exception thrown by TokenSource");
	return;
      }
      switch(token->getTokenType()) {
        case TOKEN_EOF:
	  logger->debug("TOKEN_EOF encountered");
	  return;
	default:
	  logger->debug("Unknown token encountered");
	  break;
      }
    }
  }
}

