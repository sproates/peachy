#ifndef PEACHY_LEXER_H
#define PEACHY_LEXER_H

#include "lexerstate.h"
#include "log.h"
#include "tokensource.h"

namespace peachy {

  class ScriptSource;

  class Lexer : public TokenSource {

    public:

      Lexer(Log * logger, ScriptSource * scriptSource)
        : TokenSource(logger, scriptSource) {
        logger->debug("Lexer constructor");
	state = LEXER_DEFAULT;
      }
      ~Lexer();

      Token * nextToken();

    protected:

      LexerState state;

    private:

      Lexer();
      Lexer(const Lexer & lexer);
      Lexer & operator = (const Lexer & lexer);
  };
}

#endif

