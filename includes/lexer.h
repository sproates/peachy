#ifndef PEACHY_LEXER_H
#define PEACHY_LEXER_H

#include <memory>

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

      std::auto_ptr<Token> nextToken();

    protected:

      void setState(LexerState state);
      void setCurrentLine(std::string line);

      LexerState getState();

      bool isNumeric(char c);
      bool isLetter(char c);
      bool isIdentifier(char c);
      bool isOperator(char c);
      bool isKeyword(std::string s);
      bool isLineEnding(char c);

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
