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
    return nextExpression(PARSER_NEED_TOKEN, NULL);
  }

  Expression * Parser::nextExpression(ParserState state,
    Expression * currentExpression) {

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
            return expressionFactory->createQuitExpression();
          }
          break;
        case PARSER_DEFAULT:
          logger->debug("In state PARSER_DEFAULT");
          logger->debug(tokenBuffer.front()->toString());
          switch(tokenBuffer.front()->getTokenType()) {
            case TOKEN_EOF:
              logger->debug("Current token is TOKEN_EOF");
              return expressionFactory->createQuitExpression();
            case TOKEN_IDENTIFIER:
              logger->debug("Current token is TOKEN_IDENTIFIER");
              switch(tokenBuffer[1]->getTokenType()) {
                case TOKEN_OPERATOR:
                  logger->debug("Next token is TOKEN_OPERATOR");
                  if(tokenBuffer[1]->getData().compare("<-") == 0) {
                    logger->debug("Looks like an assignment");
                    state = PARSER_ASSIGNMENT;
                    AssignmentExpression * ae =
                      expressionFactory->createAssignmentExpression();
                    VariableExpression * e =
                      expressionFactory->createVariableExpression();
                    e->setVariableName(tokenBuffer[0]->getData());
                    ae->setLValue(e);
                    tokenBuffer.pop_front();
                    tokenBuffer.pop_front();
                    return nextExpression(PARSER_ASSIGNMENT, ae);
                  } else {
                    logger->debug("I don't know what to do with that operator");
                    errorMessage = std::string("I don't know what to do with that operator");
                    state = PARSER_ERROR;
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
              tokenBuffer.pop_front();
              state = PARSER_NEED_TOKEN;
              break;
            default:
              logger->debug("Unknown token type");
              errorMessage = std::string("Unknown token type encountered");
              state = PARSER_ERROR;
          }
          break;
        case PARSER_ASSIGNMENT:
          logger->debug("In state PARSER_ASSIGNMENT");
          AssignmentExpression * expression = static_cast<AssignmentExpression*>(currentExpression);
          switch(tokenBuffer.front()->getTokenType()) {
            case TOKEN_NUMBER:
              logger->debug("Assigning a number");
              errorMessage = std::string("I don't know how to assign numbers yet");
              state = PARSER_ERROR;
              break;
            case TOKEN_STRING:
              logger->debug("Assigning a string?");
              switch(tokenBuffer[1]->getTokenType()) {
                case TOKEN_OPERATOR:
                  logger->debug("Uh oh, next token is an operator");
                  errorMessage = std::string("I don't know what to do when an operator follows a string in an assignment");
                  state = PARSER_ERROR;
                  break;
                case TOKEN_EOF:
                case TOKEN_IDENTIFIER:
                  logger->debug("Ok, looks like we got the end of the statement");
                  StringLiteralExpression * s =
                    expressionFactory->createStringLiteralExpression();
                  s->setStringValue(tokenBuffer.front()->getData());
                  expression->setRValue(s);
                  tokenBuffer.pop_front();
                  return expression;
                default:
                  logger->debug("Ok I have no idea what's going on");
                  errorMessage = std::string("Unknown token sequence");
                  state = PARSER_ERROR;
              }
              break;
            default:
              logger->debug("Unknown type of assignment");
              errorMessage = std::string("I don't know how to do that kind of assignment");
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
    while(tokenBuffer.size() < 2) {
      Token * token = tokenSource->nextToken();
      logger->debug("Adding token to buffer:");
      logger->debug(token->toString());
      tokenBuffer.push_back(token);
    }
  }
}
