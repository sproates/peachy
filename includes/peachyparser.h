#ifndef PEACHY_PEACHYPARSER_H
#define PEACHY_PEACHYPARSER_H

#include <memory>

#include "expressionsource.h"
#include "log.h"
#include "parserstate.h"

namespace peachy {

  class ExpressionFactory;

  class PeachyParser : public ExpressionSource {

    public:

      PeachyParser(Log * logger, ExpressionFactory * expressionFactory,
        TokenSource * tokenSource)
        : ExpressionSource(logger, expressionFactory, tokenSource) {
        logger->debug("PeachyParser constuctor");
        setState(PARSER_NEED_TOKEN);
      }

      ~PeachyParser();

      std::auto_ptr<Expression> nextExpression();

    private:

      ParserState state;

      void setState(ParserState state);
      ParserState getState();

      PeachyParser();
      PeachyParser(const PeachyParser & peachyParser);
      PeachyParser & operator = (const PeachyParser & peachyParser);
  };
}

#endif
