#include "tokenfactory.h"

#include <string>

#include "log.h"
#include "token.h"
#include "tokentype.h"

namespace peachy {

  TokenFactory::TokenFactory(Log * logger, Log * tokenLogger) {
    logger->debug("TokenFactory constructor");
    this->logger = logger;
    this->tokenLogger = tokenLogger;
  }

  TokenFactory::~TokenFactory() {
    logger->debug("TokenFactory destructor");
  }

  Token * TokenFactory::createToken(TokenType tokenType) {
    logger->debug("TokenFactory::createToken()");
    return new Token(tokenLogger, tokenType);
  }

  Token * TokenFactory::createToken(TokenType tokenType, std::string data) {
    logger->debug("TokenFactory::createToken()");
    return new Token(tokenLogger, tokenType, data);
  }

  Token * TokenFactory::createToken(Log * logger, TokenType tokenType) {
    this->logger->debug("TokenFactory::createToken()");
    return new Token(logger, tokenType);
  }

  Token * TokenFactory::createToken(Log * logger, TokenType tokenType,
                                    std::string data) {
    this->logger->debug("TokenFactory::createToken()");
    return new Token(logger, tokenType, data);
  }
}
