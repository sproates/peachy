#ifndef PEACHY_LEXER_H
#define PEACHY_LEXER_H

#include "log.h"
#include "tokensource.h"

namespace peachy {

  class Lexer : public TokenSource {

    public:

      Lexer(Log * logger) : TokenSource(logger) {
        logger->debug("Lexer constructor");
      }
      ~Lexer();

    private:

      Lexer();
      Lexer(const Lexer & lexer);
      Lexer & operator = (const Lexer & lexer);
  };
}

#endif

