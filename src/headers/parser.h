#ifndef PEACHY_PARSER_H
#define PEACHY_PARSER_H

namespace peachy {

  class Log;
  class Script;

  class Parser {

    public:

      Parser(Log * logger, Script * script);
      ~Parser();

    private:

      Log * logger;
      Script * script;

      Parser();
  };
}

#endif

