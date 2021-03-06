#ifndef PEACHY_LEXER_H
#define PEACHY_LEXER_H

#include <string>

#include "lexerstate.h"
#include "log.h"
#include "tokensource.h"

namespace peachy {

  class ScriptSource;
  class TokenFactory;

  class Lexer : public TokenSource {

    public:

      Lexer(Log * logger, TokenFactory * tokenFactory,
            ScriptSource * scriptSource)
        : TokenSource(logger, tokenFactory, scriptSource) {
        logger->debug("Lexer constructor");
        setState(LEXER_NEED_INPUT);
        currentPos = 0;
      }
      ~Lexer();

      Token * nextToken();

    protected:

      void setState(LexerState state);
      void setCurrentLine(std::string line);
      bool atEndOfLine();

      LexerState getState();

      bool isNumeric(char c);
      bool isLetter(char c);
      bool isIdentifier(char c);
      bool isOperatorChar(char c);
      bool isKeyword(std::string s);
      bool isLineEnding(char c);
      bool isOperator(std::string s);

    private:

      void resetLine();
      void resetToken();
      void consume(bool appendChar);

      LexerState state;

      char currentChar;
      unsigned int currentPos;
      std::string currentLine;
      std::string currentSequence;

      Lexer();
      Lexer(const Lexer & lexer);
      Lexer & operator = (const Lexer & lexer);
  };
}

#endif
