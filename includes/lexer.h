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
	setState(LEXER_NEED_INPUT);
	currentPos = 0;
      }
      ~Lexer();

      Token * nextToken();

    protected:

      LexerState state;
      std::string currentLine;
      unsigned int currentPos;
      char currentChar;

      void setState(LexerState state);
      void setCurrentLine(std::string line);

      bool isNumeric(char c);
      bool isLetter(char c);
      bool isIdentifier(char c);
      bool isOperator(char c);

    private:

      Lexer();
      Lexer(const Lexer & lexer);
      Lexer & operator = (const Lexer & lexer);
  };
}

#endif
