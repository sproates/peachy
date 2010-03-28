#include "lexer.h"

#include <stdexcept>
#include <string>

#include "log.h"
#include "scriptsource.h"
#include "token.h"

namespace peachy {

  Lexer::~Lexer() {
    logger->debug("Lexer destructor");
  }

  Token * Lexer::nextToken() {
    logger->debug("Lexer::nextToken()");

    Token * token;
    bool gotToken = false;

    while(!gotToken) {
      char currentChar = currentLine[currentPos];
      switch(state) {
        case LEXER_COMPLETE:
	  logger->debug("In state LEXER_COMPLETE");
	  token = new Token(logger, TOKEN_EOF);
	  gotToken = true;
          break;
        case LEXER_DEFAULT:
          logger->debug("In state LEXER_DEFAULT");
          switch(currentChar) {
	    case ' ':
	    case '\t':
	      logger->debug("Whitespace");
	      currentPos++;
	      break;
	    case '\n':
	    case '\r':
	    case NULL:
	      logger->debug("End of line");
	      setState(LEXER_NEED_INPUT);
	      currentPos = 0;
	      break;
            default:
	      if(isNumeric(currentChar)) {
                logger->debug("Current char is a number");
		setState(LEXER_IN_NUMBER);
		currentPos++;
	      } else if(isLetter(currentChar)) {
	        logger->debug("Current char is a letter");
                setState(LEXER_IN_IDENTIFIER);
                currentPos++;
              } else if(isOperator(currentChar)) {
	        logger->debug("Current char is an operator");
		setState(LEXER_IN_OPERATOR);
		currentPos++;
	      } else {
                throw std::runtime_error(
		  std::string("Invalid character encountered: ").append(
		    1, currentChar));
	      }
	      break;
	  }
          break;
	case LEXER_IN_NUMBER:
	  logger->debug("In state LEXER_IN_NUMBER");
	  if(isNumeric(currentChar)) {
            logger->debug("Another digit of the current number");
	    currentPos++;
	  } else {
            logger->debug("End of number");
	    setState(LEXER_DEFAULT);
            return new Token(logger, TOKEN_NUMBER, std::string(""));
	  }
	  break;
	case LEXER_IN_IDENTIFIER:
	  logger->debug("In state LEXER_IN_IDENTIFIER");
	  if(isIdentifier(currentChar)) {
            logger->debug("Another character of the current identifier");
	    currentPos++;
	  } else {
            logger->debug("End of identifier");
	    setState(LEXER_DEFAULT);
	    return new Token(logger, TOKEN_IDENTIFIER, std::string(""));
	  }
	  break;
	case LEXER_IN_OPERATOR:
	  logger->debug("In state LEXER_IN_OPERATOR");
	  if(isOperator(currentChar)) {
            logger->debug("Another character of the current operator");
	    currentPos++;
	  } else {
            logger->debug("End of operator");
	    setState(LEXER_DEFAULT);
	    return new Token(logger, TOKEN_OPERATOR, std::string(""));
	  }
	  break;
        case LEXER_NEED_INPUT:
          logger->debug("In state LEXER_NEED_INPUT");
	  if(!scriptSource->hasMoreLines()) {
            logger->debug("End of input");
	    setState(LEXER_COMPLETE);
	  } else {
            setCurrentLine(scriptSource->getLine());
	    logger->debug("Got new line from script source");
	    setState(LEXER_DEFAULT);
	  }
          break;
	case LEXER_ERROR:
          logger->debug("In state LEXER_ERROR");
          break;
	default:
          logger->debug("In an unknown state");
          this->state = LEXER_ERROR;
          break;
      }
    }

    return token;
  }

  void Lexer::setState(LexerState state) {
    logger->debug("Lexer::setState()");
    this->state = state;
  }

  void Lexer::setCurrentLine(std::string line) {
    logger->debug("Lexer::setCurrentLine()");
    this->currentLine = line;
  }

  bool Lexer::isNumeric(char c) {
    return (
      c >= '0' &&
      c <= '9'
    );
  }

  bool Lexer::isLetter(char c) {
    return (
      ( c >= 'a' && c <= 'z' ) ||
      ( c >= 'A' && c <= 'Z' )
    );
  }

  bool Lexer::isOperator(char c) {
    return (
      c == '='
    );
  }

  bool Lexer::isIdentifier(char c) {
    return (
      isLetter(c) ||
      isNumeric(c)
    );
  }
}

