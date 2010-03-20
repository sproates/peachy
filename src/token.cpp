#include "token.h"

#include <string>

#include "log.h"

namespace peachy {

  void Token::construct(Log * logger, TokenType tokenType, std::string text) {
    logger->debug("Token::construct()");
    this->logger = logger;
    this->tokenType = tokenType;
    this->text = text;
  }

  Token::Token(Log * logger) {
    logger->debug("Token constructor");
    construct(logger, TOKEN_EMPTY, std::string(""));
  }

  Token::Token(Log * logger, TokenType tokenType, std::string text) {
    logger->debug("Token constructor");
    construct(logger, tokenType, text);
  }

  Token::~Token() {
    logger->debug("Token destructor");
  }

  std::string Token::getText() const {
    logger->debug("Token::getText()");
    return text;
  }

  TokenType Token::getTokenType() const {
    logger->debug("Token::getTokenType()");
    return tokenType;
  }

  std::ostream & operator << (std::ostream & outputStream,
                              const Token & token) {
    switch(token.getTokenType()) {

      case TOKEN_EMPTY:
        outputStream << "empty";
	break;
      case TOKEN_EOF:
        outputStream << "EOF";
        break;
      case TOKEN_IDENTIFIER:
        outputStream << "identifier: " << token.getText();
        break;
      case TOKEN_INTEGER:
        outputStream << "integer";
        break;
      case TOKEN_KEYWORD:
        outputStream << "keyword: " << token.getText();
        break;
      case TOKEN_NEWLINE:
        outputStream << "new line";
        break;
      case TOKEN_OPERATOR:
        outputStream << "operator: " << token.getText();
        break;
      case TOKEN_STRING:
        outputStream << "string: " << token.getText();
        break;
      default:
        outputStream << "unknown token";
	break;
    }
    return outputStream;
  }
}

