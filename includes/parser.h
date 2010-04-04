#ifndef PEACHY_PARSER_H
#define PEACHY_PARSER_H

#include <memory>

#include "expressionsource.h"
#include "log.h"
#include "parserstate.h"

namespace peachy {

  class ExpressionFactory;

  class Parser : public ExpressionSource {

    public:

      Parser(Log * logger, ExpressionFactory * expressionFactory,
        TokenSource * tokenSource)
        : ExpressionSource(logger, expressionFactory, tokenSource) {
        logger->debug("Parser constuctor");
        setState(PARSER_NEED_TOKEN);
      }

      ~Parser();

      std::auto_ptr<Expression> nextExpression();

    private:

      ParserState state;

      void setState(ParserState state);
      ParserState getState();

      Parser();
      Parser(const Parser & p);
      Parser & operator = (const Parser & p);
  };
}

#endif
