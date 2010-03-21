#ifndef PEACHY_TOKEN_H
#define PEACHY_TOKEN_H

#include <ostream>
#include <string>

namespace peachy {

  class Log;

  enum TokenType {

    TOKEN_EMPTY,
    TOKEN_EOF,
    TOKEN_IDENTIFIER,
    TOKEN_INTEGER,
    TOKEN_KEYWORD,
    TOKEN_NEWLINE,
    TOKEN_OPERATOR,
    TOKEN_STRING
  };

  class Token {

    public:

      Token(Log * logger);
      Token(Log * logger, TokenType tokenType, std::string data);
      ~Token();

      TokenType getTokenType() const;
      std::string getData() const;
      std::string toString();

    private:

      Log * logger;
      TokenType tokenType;
      std::string data;

      void construct(Log * logger, TokenType tokenType, std::string data);

      Token();
      Token(const Token & token);
      Token & operator = (const Token & token);
  };
}

#endif

