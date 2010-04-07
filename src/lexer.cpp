#include "lexer.h"

#include <string>

#include "lexerexception.h"
#include "log.h"
#include "scriptsource.h"
#include "token.h"
#include "tokenfactory.h"

namespace peachy {

  Lexer::~Lexer() {
    logger->debug("Lexer destructor");
  }

  Token * Lexer::nextToken() {
    logger->debug("Lexer::nextToken()");

    Token * token;
    bool gotToken = false;

    while(!gotToken) {
      if(atEndOfLine()) {
        logger->debug("Overflowed input buffer");
        throw LexerException("Overflowed input buffer");
      }
      currentChar = currentLine[currentPos];
      switch(state) {
        case LEXER_COMPLETE:
          logger->debug("In state LEXER_COMPLETE");
          token = tokenFactory->createToken(TOKEN_EOF);
          gotToken = true;
          break;
        case LEXER_DEFAULT:
          logger->debug("In state LEXER_DEFAULT");
          switch(currentChar) {
            case ' ':
            case '\t':
              logger->debug("Whitespace");
              consume(false);
              break;
            case '\n':
            case '\r':
            case NULL:
              logger->debug("End of line");
              resetLine();
              break;
            case ':':
              logger->debug("Colon");
              token = tokenFactory->createToken(TOKEN_COLON);
              resetToken();
              gotToken = true;
              break; 
            case '{':
              logger->debug("Left brace");
              token = tokenFactory->createToken(TOKEN_LEFT_BRACE);
              resetToken();
              gotToken = true;
              break;
            case '[':
              logger->debug("Left bracket");
              token = tokenFactory->createToken(TOKEN_LEFT_BRACKET);
              resetToken();
              gotToken = true;
              break;
            case '(':
              logger->debug("Left paren");
              token = tokenFactory->createToken(TOKEN_LEFT_PARENTHESIS);
              resetToken();
              gotToken = true;
              break;
            case '}':
              logger->debug("Right brace");
              token = tokenFactory->createToken(TOKEN_RIGHT_BRACE);
              resetToken();
              gotToken = true;
              break;
            case ']':
              logger->debug("Right bracket");
              token = tokenFactory->createToken(TOKEN_RIGHT_BRACKET);
              resetToken();
              gotToken = true;
              break;
            case ')':
              logger->debug("Right paren");
              token = tokenFactory->createToken(TOKEN_RIGHT_PARENTHESIS);
              resetToken();
              gotToken = true;
              break;
            case '#':
              logger->debug("Comment line");
              setState(LEXER_IN_COMMENT_LINE);
              consume(false);
              break;
            case '"':
              logger->debug("Start of string");
              setState(LEXER_IN_STRING);
              consume(false);
              break;
            default:
              if(isNumeric(currentChar)) {
                logger->debug("Current char is a number");
                setState(LEXER_IN_NUMBER);
                consume(true);
              } else if(isLetter(currentChar)) {
                logger->debug("Current char is a letter");
                setState(LEXER_IN_IDENTIFIER);
                consume(true);
              } else if(isOperatorChar(currentChar)) {
                logger->debug("Current char is an operator");
                setState(LEXER_IN_OPERATOR);
                consume(true);
              } else {
                throw LexerException(
                  std::string("Invalid character encountered: ").append(
                    1, currentChar));
              }
          }
          break;
        case LEXER_IN_STRING:
          logger->debug("In state LEXER_IN_STRING");
          switch(currentChar) {
            case '"':
              logger->debug("End quote");
              token = tokenFactory->createToken(TOKEN_STRING, currentSequence);
              consume(false);
              resetToken();
              gotToken = true;
              break;
            case 0:
              logger->debug("Newline found");
              currentSequence.append(1, '\n');
              logger->debug(currentSequence);
              if(!scriptSource->hasMoreLines()) {
                logger->debug("End of input but still inside string");
                throw LexerException("Input terminated inside open string");
              } else {
                logger->debug("Getting a new line from script source");
                setCurrentLine(scriptSource->getLine());
                currentPos = 0;
              }
              break;
            default:
              logger->debug("Ordinary character");
              consume(true);
              logger->debug(currentSequence);
              break;
          }
          break;
        case LEXER_IN_NUMBER:
          logger->debug("In state LEXER_IN_NUMBER");
          if(isNumeric(currentChar)) {
            logger->debug("Another digit of the current number");
            consume(true);
          } else {
            logger->debug("End of number");
            token = tokenFactory->createToken(TOKEN_NUMBER, currentSequence);
            resetToken();
            gotToken = true;
          }
          break;
        case LEXER_IN_IDENTIFIER:
          logger->debug("In state LEXER_IN_IDENTIFIER");
          if(isIdentifier(currentChar)) {
            logger->debug("Another character of the current identifier");
            consume(true);
          } else {
            logger->debug("End of identifier");
            if(isKeyword(currentSequence)) {
              token = tokenFactory->createToken(TOKEN_KEYWORD, currentSequence);
            } else {
              token = tokenFactory->createToken(TOKEN_IDENTIFIER,
                currentSequence);
            }
            resetToken();
            gotToken = true;
          }
          break;
        case LEXER_IN_OPERATOR:
          logger->debug("In state LEXER_IN_OPERATOR");
          if(isOperatorChar(currentChar)) {
            logger->debug("Another character of the current operator");
            consume(true);
          } else if(isNumeric(currentChar) &&
            currentSequence.compare("-") == 0) {
            logger->debug("Looks like a negative number");
            setState(LEXER_IN_NUMBER);
            consume(true);
          } else {
            if(isOperator(currentSequence)) {
              logger->debug("End of operator");
              token = tokenFactory->createToken(TOKEN_OPERATOR, currentSequence);
              resetToken();
              gotToken = true;
            } else {
              logger->debug("Invalid operator sequence");
              throw LexerException("Invalid operator sequence");
            }
          }
          break;
        case LEXER_IN_COMMENT_LINE:
          logger->debug("In state LEXER_IN_COMMENT_LINE");
          if(isLineEnding(currentChar)) {
            logger->debug("End of comment");
            token = tokenFactory->createToken(TOKEN_COMMENT_LINE,
              currentSequence);
            resetToken();
            gotToken = true;
          } else {
            logger->debug("Another character of the current comment");
            consume(true);
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
            resetToken();
          }
          break;
        case LEXER_ERROR:
          logger->debug("In state LEXER_ERROR");
          throw LexerException("Invalid lexer state");
          break;
        default:
          logger->debug("In an unknown state");
          setState(LEXER_ERROR);
          break;
      }
    }

    return token;
  }

  void Lexer::consume(bool appendChar) {
    logger->debug("Lexer::consume()");
    if(appendChar) {
      currentSequence.append(1, currentChar);
    }
    currentPos++;
  }

  bool Lexer::atEndOfLine() {
    return(currentPos > currentLine.length());
  }

  void Lexer::resetLine() {
    logger->debug("Lexer::resetLine()");
    setState(LEXER_NEED_INPUT);
    currentPos = 0;
  }

  void Lexer::resetToken() {
    logger->debug("Lexer::resetToken()");
    setState(LEXER_DEFAULT);
    currentSequence = std::string("");
  }

  void Lexer::setState(LexerState state) {
    logger->debug("Lexer::setState()");
    this->state = state;
  }

  void Lexer::setCurrentLine(std::string line) {
    logger->debug("Lexer::setCurrentLine()");
    this->currentLine = line;
  }

  LexerState Lexer::getState() {
    logger->debug("Lexer::getState()");
    return this->state;
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

  bool Lexer::isOperatorChar(char c) {
    return (
      c == '=' ||
      c == '-' ||
      c == '+' ||
      c == '>' ||
      c == '<' ||
      c == '|'
    );
  }

  bool Lexer::isOperator(std::string s) {
    return (
      s.compare("<-") == 0 ||
      s.compare("=") == 0 ||
      s.compare(">=") == 0 ||
      s.compare("<=") == 0 ||
      s.compare("<") == 0 ||
      s.compare(">") == 0 ||
      s.compare("+") == 0 ||
      s.compare("-") == 0 ||
      s.compare("|") == 0 ||
      s.compare("&") == 0      
    );
  }

  bool Lexer::isIdentifier(char c) {
    return (
      isLetter(c) ||
      isNumeric(c) ||
      c == '_'
    );
  }

  bool Lexer::isKeyword(std::string s) {
    return (
      s.compare("while") == 0 ||
      s.compare("function") == 0 ||
      s.compare("return") == 0 ||
      s.compare("class") == 0 ||
      s.compare("for") == 0 ||
      s.compare("print") == 0
    );
  }

  bool Lexer::isLineEnding(char c) {
    return (
      c == '\r' ||
      c == '\n'
    );
  }
}

