#ifndef PEACHY_LEXER_H
#define PEACHY_LEXER_H

#include "log.h"
#include "tokensource.h"

namespace peachy {

  class ScriptSource;

  class Lexer : public TokenSource {

    public:

      Lexer(Log * logger, ScriptSource * scriptSource)
        : TokenSource(logger, scriptSource) {
        logger->debug("Lexer constructor");
      }
      ~Lexer();

      Token * nextToken();

    private:

      Lexer();
      Lexer(const Lexer & lexer);
      Lexer & operator = (const Lexer & lexer);
  };
}

#endif

