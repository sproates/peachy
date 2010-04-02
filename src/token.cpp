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

  Token::Token(Log * logger, TokenType tokenType) {
    logger->debug("Token constructor");
    construct(logger, tokenType, std::string(""));
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
      case TOKEN_COMMENT_LINE:
        return std::string("comment line: ").append(data);
      case TOKEN_EMPTY:
        return std::string("empty");
      case TOKEN_EOF:
        return std::string("EOF");
      case TOKEN_IDENTIFIER:
        return std::string("identifier: ").append(data);
      case TOKEN_INTEGER:
        return std::string("integer: ").append(data);
      case TOKEN_KEYWORD:
        return std::string("keyword: ").append(data);
      case TOKEN_LEFT_PARENTHESIS:
        return std::string("left parenthesis");
      case TOKEN_NEWLINE:
        return std::string("new line");
      case TOKEN_NUMBER:
        return std::string("number: ").append(data);
      case TOKEN_OPERATOR:
        return std::string("operator: ").append(data);
      case TOKEN_RIGHT_PARENTHESIS:
        return std::string("right parenthesis");
      case TOKEN_STRING:
        return std::string("string: ").append(data);
      default:
        return std::string("unknown token");
    }
  }
}
