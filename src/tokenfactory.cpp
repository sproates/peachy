#include "tokenfactory.h"

#include <string>

#include "log.h"
#include "token.h"

namespace peachy {

  TokenFactory::TokenFactory(Log * logger, Log * tokenLogger) {
    logger->debug("TokenFactory constructor");
    this->logger = logger;
    this->tokenLogger = tokenLogger;
  }

  TokenFactory::~TokenFactory() {
    logger->debug("TokenFactory destructor");
  }

  Token * TokenFactory::createToken(Log * logger, TokenType tokenType) {
    return new Token(logger, tokenType);
  }

  Token * TokenFactory::createToken(Log * logger, TokenType tokenType,
                                    std::string data) {
    return new Token(logger, tokenType, data);
  }
}
