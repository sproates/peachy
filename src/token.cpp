#include "token.h"

#include "log.h"

namespace peachy {

  void Token::construct(Log * logger, TokenType tokenType) {
    logger->debug("Token construct");
    this->logger = logger;
    this->tokenType = tokenType;
  }

  Token::Token(Log * logger) {
    logger->debug("Token constructor");
    construct(logger, TOKEN_EMPTY);
  }

  Token::Token(Log * logger, TokenType tokenType) {
    logger->debug("Token constructor");
    construct(logger, tokenType);
  }

  Token::~Token() {
    logger->debug("Token destructor");
  }
}

