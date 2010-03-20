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
      Token(Log * logger, TokenType tokenType, std::string text);
      ~Token();

      TokenType getTokenType() const;
      std::string getText() const;

    private:

      Log * logger;
      TokenType tokenType;
      std::string text;

      void construct(Log * logger, TokenType tokenType, std::string text);

      Token();
      Token(const Token & token);
      Token & operator = (const Token & token);
  };

  std::ostream & operator << (std::ostream & outputStream, const Token & token);
}

#endif

