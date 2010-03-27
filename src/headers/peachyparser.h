#ifndef PEACHY_PEACHYPARSER_H
#define PEACHY_PEACHYPARSER_H

#include "log.h"
#include "parser.h"

namespace peachy {

  class Log;

  class PeachyParser : public Parser {

    public:

      PeachyParser(Log * logger, TokenSource * tokenSource)
        : Parser(logger, tokenSource) {
        logger->debug("PeachyParser constuctor");
      }

      ~PeachyParser();

      void parse();

    private:

      PeachyParser();
      PeachyParser(const PeachyParser & peachyParser);
      PeachyParser & operator = (const PeachyParser & peachyParser);
  };
}

#endif
