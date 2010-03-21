#include "token.h"

#include <string>

#include "log.h"
#include "tokentype.h"

namespace peachy {

  void Token::construct(Log * logger, TokenType tokenType, std::string data) {
    logger->debug("Token::construct()");
    this->logger = logger;
    this->tokenType = tokenType;
    this->data = data;
  }

  Token::Token(Log * logger) {
    logger->debug("Token constructor");
    construct(logger, TOKEN_EMPTY, std::string(""));
  }

  Token::Token(Log * logger, TokenType tokenType, std::string data) {
    logger->debug("Token constructor");
    construct(logger, tokenType, data);
  }

  Token::~Token() {
    logger->debug("Token destructor");
  }

  std::string Token::getData() const {
    logger->debug("Token::getData()");
    return data;
  }

  TokenType Token::getTokenType() const {
    logger->debug("Token::getTokenType()");
    return tokenType;
  }

  std::string Token::toString() {
    switch(tokenType) {
      case TOKEN_EMPTY:
        return std::string("empty");
	break;
      case TOKEN_EOF:
        return std::string("EOF");
        break;
      case TOKEN_IDENTIFIER:
        return std::string("identifier: ").append(data);
        break;
      case TOKEN_INTEGER:
        return std::string("integer: ").append(data);
        break;
      case TOKEN_KEYWORD:
        return std::string("keyword: ").append(data);
        break;
      case TOKEN_NEWLINE:
        return std::string("new line");
        break;
      case TOKEN_OPERATOR:
        return std::string("operator: ").append(data);
        break;
      case TOKEN_STRING:
        return std::string("string: ").append(data);
        break;
      default:
        return std::string("unknown token");
	break;
    }
  }
}

