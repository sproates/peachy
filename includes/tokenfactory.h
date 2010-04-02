#ifndef PEACHY_TOKENFACTORY_H
#define PEACHY_TOKENFACTORY_H

#include <string>

#include "tokentype.h"

namespace peachy {

  class Log;
  class Token;

  class TokenFactory {

    public:

      TokenFactory(Log * logger, Log * tokenLogger);
      virtual ~TokenFactory();
      Token * createToken(Log * logger, TokenType tokenType);
      Token * createToken(Log * logger, TokenType tokenType, std::string data);

    protected:

      Log * logger;
      Log * tokenLogger;

    private:

      TokenFactory();
      TokenFactory(const TokenFactory & tokenFactory);
      TokenFactory & operator = (const TokenFactory & tokenFactory);
  };
}

#endif
