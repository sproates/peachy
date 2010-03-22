#include "lexer.h"

#include "log.h"
#include "token.h"

namespace peachy {

  Lexer::~Lexer() {
    logger->debug("Lexer destructor");
  }

  Token * Lexer::nextToken() {
    logger->debug("Lexer::nextToken()");
    return new Token(logger);
  }
}

