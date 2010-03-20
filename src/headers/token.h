#ifndef PEACHY_TOKEN_H
#define PEACHY_TOKEN_H

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
      Token(Log * logger, TokenType tokenType);
      ~Token();

      TokenType getTokenType();

    private:

      Log * logger;
      TokenType tokenType;

      void construct(Log * logger, TokenType tokenType);

      Token();
      Token(const Token & token);
      Token & operator = (const Token & token);
  };
}

#endif

