#include "token.h"

#include "log.h"

namespace peachy {

  Token::Token(Log * logger) {
    this->logger = logger;
    logger->debug("Token constructor");
  }

  Token::~Token() {
    logger->debug("Token destructor");
  }
}

