#ifndef PEACHY_PARSER_H
#define PEACHY_PARSER_H

namespace peachy {

  class Log;
  class TokenSource;

  class Parser {

    public:

      Parser(Log * logger, TokenSource * tokenSource);
      virtual ~Parser();

      virtual void parse() = 0;

    protected:

      Log * logger;
      TokenSource * tokenSource;

    private:

      Parser();
  };
}

#endif
