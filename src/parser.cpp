#include "parser.h"

#include "assignmentexpression.h"
#include "expression.h"
#include "expressionfactory.h"
#include "lexerexception.h"
#include "log.h"
#include "parserexception.h"
#include "parserstate.h"
#include "quitexpression.h"
#include "stringliteralexpression.h"
#include "token.h"
#include "tokensource.h"
#include "variableexpression.h"

namespace peachy {

  Parser::~Parser() {
    logger->debug("Parser destructor");
  }

  Expression * Parser::nextExpression() {
    logger->debug("Parser::nextExpression()");
    return nextExpression(PARSER_NEED_TOKEN);
  }

  Expression * Parser::nextExpression(ParserState state) {
    while(true) {
      fillTokenBuffer();
      switch(state) {
        case PARSER_NEED_TOKEN:
          logger->debug("In state PARSER_NEED_TOKEN");
          if(tokenBuffer.size() > 0) {
            logger->debug("Got more tokens");
            state = PARSER_DEFAULT;
          } else {
            logger->debug("No more tokens");
            logger->debug("Finished current expression");
            return expressionFactory->createQuitExpression();
          }
          break;
        case PARSER_DEFAULT:
          logger->debug("In state PARSER_DEFAULT");
          logger->debug(tokenBuffer.front()->toString());
          switch(tokenBuffer.front()->getTokenType()) {
            case TOKEN_EOF:
              logger->debug("Current token is TOKEN_EOF");
              logger->debug("Finished current expression");
              return expressionFactory->createQuitExpression();
            case TOKEN_IDENTIFIER:
              logger->debug("Current token is TOKEN_IDENTIFIER");
              switch(tokenBuffer[1]->getTokenType()) {
                case TOKEN_OPERATOR:
                  logger->debug("Next token is TOKEN_OPERATOR");
                  if(tokenBuffer[1]->getData().compare("<-") == 0) {
                    logger->debug("Looks like an assignment");
                    AssignmentExpression * ae =
                      expressionFactory->createAssignmentExpression();
                    VariableExpression * e =
                      expressionFactory->createVariableExpression();
                    e->setVariableName(tokenBuffer[0]->getData());
                    ae->setLValue(e);
                    tokenBuffer.pop_front();
                    tokenBuffer.pop_front();
                    logger->debug("Parser recursing to find rvalue of current assingment");
                    ae->setRValue(nextExpression(PARSER_DEFAULT));
                    logger->debug("Got rvalue of current assignment, assignment expression is complete");
                    return ae;
                  } else {
                    logger->debug("I don't know what to do with that operator");
                    errorMessage = std::string("I don't know what to do with that operator");
                    state = PARSER_ERROR;
                    break;
                  }
                  break;
                default:
                  logger->debug("I have no idea what to do with the next token");
                  errorMessage = std::string("I have no idea what to do with the next token");
                  state = PARSER_ERROR;
              }
              break;
            case TOKEN_OPERATOR:
              logger->debug("Current token is TOKEN_OPERATOR");
              tokenBuffer.pop_front();
              state = PARSER_NEED_TOKEN;
              break;
            case TOKEN_STRING:
              logger->debug("current token is TOKEN_STRING");
              switch(tokenBuffer[1]->getTokenType()) {
                case TOKEN_EOF:
                case TOKEN_IDENTIFIER:
                  logger->debug("Nothing more to do in current expression");
                  logger->debug("Returning string literal expression");
                  StringLiteralExpression * e =
                    expressionFactory->createStringLiteralExpression();
                  e->setStringValue(tokenBuffer.front()->getData());
                  tokenBuffer.pop_front();
                  return e;
                case TOKEN_OPERATOR:
                  logger->debug("Token after string literal is operator");
                  errorMessage = std::string("I don't know what to do when an operator follows a string literal");
                  state = PARSER_ERROR;
                  break;
                default:
                  logger->debug("Unknown token following string literal");
                  errorMessage = std::string("I don't know what to do when an operator follows a string literal");
                  state = PARSER_ERROR;
              }
              break;
            default:
              logger->debug("Unknown token type");
              errorMessage = std::string("Unknown token type encountered");
              state = PARSER_ERROR;
          }
          break;
        case PARSER_ERROR:
          logger->debug("In state PARSER_ERROR");
          throw ParserException(errorMessage);
        default:
          logger->debug("Unknown state");
          errorMessage = std::string("Parser in unknown state");
          state = PARSER_ERROR;
      }
    }
  }

  void Parser::fillTokenBuffer() {
    logger->debug("Parser::fillTokenBuffer()");
    while(tokenBuffer.size() < 3) {
      Token * token = tokenSource->nextToken();
      tokenBuffer.push_back(token);
    }
  }

  void Parser::logTokenBuffer() {
    logger->debug("Log of token buffer:");
    for(unsigned int i = 0; i < tokenBuffer.size(); i++) {
      logger->debug(tokenBuffer[i]->toString());
    }
  }
}
