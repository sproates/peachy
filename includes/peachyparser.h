#ifndef PEACHY_PEACHYPARSER_H
#define PEACHY_PEACHYPARSER_H

#include "log.h"
#include "parser.h"
#include "parserstate.h"

namespace peachy {

  class Log;

  class PeachyParser : public Parser {

    public:

      PeachyParser(Log * logger, TokenSource * tokenSource)
        : Parser(logger, tokenSource) {
        logger->debug("PeachyParser constuctor");
        setState(PARSER_NEED_TOKEN);
      }

      ~PeachyParser();

      void parse();

    protected:

      ParserState getState();
      void setState(ParserState state);

    private:

      ParserState state;

      PeachyParser();
      PeachyParser(const PeachyParser & peachyParser);
      PeachyParser & operator = (const PeachyParser & peachyParser);
  };
}

#endif
