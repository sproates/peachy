#include "parser.h"

#include <cstdlib>

#include "additionexpression.h"
#include "assignmentexpression.h"
#include "expression.h"
#include "expressionfactory.h"
#include "intliteralexpression.h"
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
                case TOKEN_EOF:
                  logger->debug("Next token is TOKEN_EOF");
                  logger->debug("Ok, so we just return the current identifier, which is...");
                  VariableExpression * varEx =
                    expressionFactory->createVariableExpression();
                  varEx->setVariableName(tokenBuffer[0]->getData());
                  logger->debug(varEx->getVariableName());
                  tokenBuffer.pop_front();
                  return varEx;
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
                  } else if(tokenBuffer[1]->getData().compare("+") == 0) {
                    logger->debug("Looks like an addition");
                    AdditionExpression * addEx =
                      expressionFactory->createAdditionExpression();
                    VariableExpression * varEx =
                      expressionFactory->createVariableExpression();
                    varEx->setVariableName(tokenBuffer[0]->getData());
                    addEx->setLValue(varEx);
                    tokenBuffer.pop_front();
                    tokenBuffer.pop_front();
                    logger->debug("Parser recursing to find rvalue of current addition");
                    addEx->setRValue(nextExpression(PARSER_DEFAULT));
                    logger->debug("Got rvalue of current addition, addition expression is complete");
                    return addEx;
                  } else {
                    logger->debug("I don't know what to do with that operator");
                    errorMessage = std::string("I don't know what to do with that operator");
                    state = PARSER_ERROR;
                    break;
                  }
                  break;
                default:
                  logger->debug("I have no idea what to do with the next token");
                  logger->debug(tokenBuffer[1]->getData());
                  errorMessage = std::string("I have no idea what to do with the next token");
                  state = PARSER_ERROR;
              }
              break;
            case TOKEN_INTEGER:
              logger->debug("Current token is TOKEN_INTEGER");
              switch(tokenBuffer[1]->getTokenType()) {
                case TOKEN_EOF:
                case TOKEN_IDENTIFIER:
                case TOKEN_KEYWORD:
                  logger->debug("Nothing more to do in current expression");
                  logger->debug("Returning int literal expression");
                  IntLiteralExpression * e =
                    expressionFactory->createIntLiteralExpression();
                  e->setValue(atoi(tokenBuffer.front()->getData().c_str()));
                  tokenBuffer.pop_front();
                  return e;
                case TOKEN_OPERATOR:
                  if(tokenBuffer[1]->getData().compare("+") == 0) {
                    logger->debug("Integer addition");
                    AdditionExpression * addEx =
                      expressionFactory->createAdditionExpression();
                    IntLiteralExpression * intEx =
                      expressionFactory->createIntLiteralExpression();
                    intEx->setValue(atoi(tokenBuffer[0]->getData().c_str()));
                    addEx->setLValue(intEx);
                    tokenBuffer.pop_front();
                    tokenBuffer.pop_front();
                    logger->debug("Parser recursing to find rvalue of current addition");
                    addEx->setRValue(nextExpression(PARSER_DEFAULT));
                    logger->debug("Got rvalue of current addition, addition expression is complete");
                    return addEx;
                  } else {
                    logger->debug("I don't know what to do when that operator follows an integer");
                    state = PARSER_ERROR;
                    break;
                  }
                default:
                  logger->debug("Wtf...");
                  errorMessage = std::string("I don't know what to do!!!!");
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
                case TOKEN_KEYWORD:
                  logger->debug("Nothing more to do in current expression");
                  logger->debug("Returning string literal expression");
                  StringLiteralExpression * e =
                    expressionFactory->createStringLiteralExpression();
                  e->setStringValue(tokenBuffer.front()->getData());
                  tokenBuffer.pop_front();
                  return e;
                case TOKEN_OPERATOR:
                  logger->debug("Token after string literal is operator");
                  if(tokenBuffer[1]->getData().compare("+") == 0) {
                    logger->debug("Looks like an addition");
                    AdditionExpression * addEx =
                      expressionFactory->createAdditionExpression();
                    StringLiteralExpression * stringEx =
                      expressionFactory->createStringLiteralExpression();
                    stringEx->setStringValue(tokenBuffer[0]->getData());
                    addEx->setLValue(stringEx);
                    tokenBuffer.pop_front();
                    tokenBuffer.pop_front();
                    logger->debug("Parser recursing to find rvalue of current addition");
                    addEx->setRValue(nextExpression(PARSER_DEFAULT));
                    logger->debug("Got rvalue of current addition, addition expression is complete");
                    return addEx;
                  } else {
                    errorMessage = std::string("I don't know what to do when that operator follows a string literal");
                    state = PARSER_ERROR;
                    break;
                  }
                default:
                  logger->debug("Wtf...");
                  errorMessage = std::string("I don't know what to do!!!!");
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