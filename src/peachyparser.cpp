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
	case TOKEN_IDENTIFIER:
	  logger->debug("TOKEN_IDENTIFIER encountered");
	  break;
	case TOKEN_INTEGER:
	  logger->debug("TOKEN_INTEGER encountered");
	  break;
	case TOKEN_NUMBER:
	  logger->debug("TOKEN_NUMBER encountered");
	  break;
	case TOKEN_OPERATOR:
	  logger->debug("TOKEN_OPERATOR encountered");
	  break;
	default:
	  logger->debug("Unknown token encountered");
	  break;
      }
    }
  }
}

