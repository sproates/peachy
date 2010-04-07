#ifndef PEACHY_PARSER_H
#define PEACHY_PARSER_H

#include <deque>
#include <string>

#include "expressionsource.h"
#include "log.h"
#include "parserstate.h"

namespace peachy {

  class ExpressionFactory;
  class Token;
  class TokenSource;

  class Parser : public ExpressionSource {

    public:

      Parser(Log * logger, ExpressionFactory * expressionFactory,
        TokenSource * tokenSource)
        : ExpressionSource(logger, expressionFactory, tokenSource) {
        logger->debug("Parser constuctor");
      }

      ~Parser();

      Expression * nextExpression();

    private:

      Expression * nextExpression(ParserState state,
        Expression * currentExpression);
      std::string errorMessage;
      std::deque< Token * > tokenBuffer;

      void fillTokenBuffer();

      Parser();
      Parser(const Parser & p);
      Parser & operator = (const Parser & p);
  };
}

#endif
