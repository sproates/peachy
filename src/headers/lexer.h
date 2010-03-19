#ifndef PEACHY_LEXER_H
#define PEACHY_LEXER_H

namespace peachy {

  class Log;

  class Lexer {

    public:

      Lexer(Log * logger);
      ~Lexer();

    private:

      Log * logger;

      Lexer();
      Lexer(const Lexer & lexer);
      Lexer & operator = (const Lexer & lexer);
  };
}

#endif

