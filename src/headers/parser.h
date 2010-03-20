#ifndef PEACHY_PARSER_H
#define PEACHY_PARSER_H

namespace peachy {

  class Log;

  class Parser {

    public:

      Parser(Log * logger);
      virtual ~Parser();

    private:

      Log * logger;

      Parser();
  };
}

#endif

