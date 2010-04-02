#ifndef PEACHY_TOKEN_H
#define PEACHY_TOKEN_H

#include <string>

#include "tokentype.h"

namespace peachy {

  class Log;

  class Token {

    public:

      Token(Log * logger, TokenType tokenType);
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
