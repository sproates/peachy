#include "lexer.h"

#include "log.h"
#include "token.h"

namespace peachy {

  Lexer::~Lexer() {
    logger->debug("Lexer destructor");
  }

  Token * Lexer::nextToken() {
    logger->debug("Lexer::nextToken()");

    Token * token;
    bool gotToken = false;

    while(!gotToken) {
      switch(state) {
        case LEXER_COMPLETE:
	  logger->debug("In state LEXER_COMPLETE");
	  token = new Token(logger, TOKEN_EOF);
	  gotToken = true;
          break;
        case LEXER_DEFAULT:
          logger->debug("In state LEXER_DEFAULT");
          break;
        case LEXER_NEED_INPUT:
          logger->debug("In state LEXER_NEED_INPUT");
          break;
	case LEXER_ERROR:
          logger->debug("In state LEXER_ERROR");
          break;
	default:
          logger->debug("In an unknown state");
          this->state = LEXER_ERROR;
          break;
      }
    }

    return token;
  }
}

