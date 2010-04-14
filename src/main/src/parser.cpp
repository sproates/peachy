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

  Parser::~Parser() {}

  Expression * Parser::nextExpression() {
    return nextExpression(PARSER_NEED_TOKEN);
  }

  Expression * Parser::nextExpression(ParserState state) {
    while(true) {
      fillTokenBuffer();
      switch(state) {
        case PARSER_NEED_TOKEN:
          if(tokenBuffer.size() > 0) {
            state = PARSER_DEFAULT;
            break;
          }
          return expressionFactory->createQuitExpression();
        case PARSER_DEFAULT:
          switch(tokenBuffer.front()->getTokenType()) {
            case TOKEN_EOF:
              return expressionFactory->createQuitExpression();
            case TOKEN_IDENTIFIER:
              switch(tokenBuffer[1]->getTokenType()) {
                case TOKEN_EOF:
                case TOKEN_IDENTIFIER:
                  VariableExpression * varEx =
                    expressionFactory->createVariableExpression();
                  varEx->setVariableName(tokenBuffer[0]->getData());
                  tokenBuffer.pop_front();
                  return varEx;
                case TOKEN_OPERATOR:
                  if(tokenBuffer[1]->getData().compare("<-") == 0) {
                    AssignmentExpression * ae =
                      expressionFactory->createAssignmentExpression();
                    VariableExpression * e =
                      expressionFactory->createVariableExpression();
                    e->setVariableName(tokenBuffer[0]->getData());
                    ae->setLValue(e);
                    tokenBuffer.pop_front();
                    tokenBuffer.pop_front();
                    ae->setRValue(nextExpression(PARSER_DEFAULT));
                    return ae;
                  } else if(tokenBuffer[1]->getData().compare("+") == 0) {
                    AdditionExpression * addEx =
                      expressionFactory->createAdditionExpression();
                    VariableExpression * varEx =
                      expressionFactory->createVariableExpression();
                    varEx->setVariableName(tokenBuffer[0]->getData());
                    addEx->setLValue(varEx);
                    tokenBuffer.pop_front();
                    tokenBuffer.pop_front();
                    addEx->setRValue(nextExpression(PARSER_DEFAULT));
                    return addEx;
                  } else {
                    errorMessage = std::string("Unexpected operator");
                    state = PARSER_ERROR;
                    break;
                  }
                  break;
                default:
                  errorMessage = std::string("Unexpected token type");
                  state = PARSER_ERROR;
              }
              break;
            case TOKEN_INTEGER:
              IntLiteralExpression * e =
                expressionFactory->createIntLiteralExpression();
              e->setValue(atoi(tokenBuffer.front()->getData().c_str()));
              switch(tokenBuffer[1]->getTokenType()) {
                case TOKEN_EOF:
                case TOKEN_IDENTIFIER:
                case TOKEN_KEYWORD:
                  tokenBuffer.pop_front();
                  return e;
                case TOKEN_OPERATOR:
                  if(tokenBuffer[1]->getData().compare("+") == 0) {
                    AdditionExpression * addEx =
                      expressionFactory->createAdditionExpression();
                    IntLiteralExpression * intEx =
                      expressionFactory->createIntLiteralExpression();
                    intEx->setValue(atoi(tokenBuffer[0]->getData().c_str()));
                    addEx->setLValue(intEx);
                    tokenBuffer.pop_front();
                    tokenBuffer.pop_front();
                    addEx->setRValue(nextExpression(PARSER_DEFAULT));
                    return addEx;
                  } else if(tokenBuffer[1]->getData().compare("<-") == 0 ) {
                    errorMessage = std::string("Invalid assignment");
                    state = PARSER_ERROR;
                    break;
                  } else if(tokenBuffer[1]->getData().compare("->") == 0 ) {
                    AssignmentExpression * ae =
                      expressionFactory->createAssignmentExpression();
                    ae->setRValue(e);
                    tokenBuffer.pop_front();
                    tokenBuffer.pop_front();
                    Expression * lValue = nextExpression(PARSER_DEFAULT);
                    ae->setLValue(lValue);
                    return ae;
                  } else {
                    errorMessage = std::string("Unexpected operator");
                    state = PARSER_ERROR;
                    break;
                  }
                default:
                  errorMessage = std::string("Unexpected token");
                  state = PARSER_ERROR;
              }
              break;
            case TOKEN_OPERATOR:
              tokenBuffer.pop_front();
              state = PARSER_NEED_TOKEN;
              break;
            case TOKEN_STRING:
              switch(tokenBuffer[1]->getTokenType()) {
                case TOKEN_EOF:
                case TOKEN_IDENTIFIER:
                case TOKEN_KEYWORD:
                  StringLiteralExpression * e =
                    expressionFactory->createStringLiteralExpression();
                  e->setStringValue(tokenBuffer.front()->getData());
                  tokenBuffer.pop_front();
                  return e;
                case TOKEN_OPERATOR:
                  if(tokenBuffer[1]->getData().compare("+") == 0) {
                    AdditionExpression * addEx =
                      expressionFactory->createAdditionExpression();
                    StringLiteralExpression * stringEx =
                      expressionFactory->createStringLiteralExpression();
                    stringEx->setStringValue(tokenBuffer[0]->getData());
                    addEx->setLValue(stringEx);
                    tokenBuffer.pop_front();
                    tokenBuffer.pop_front();
                    addEx->setRValue(nextExpression(PARSER_DEFAULT));
                    return addEx;
                  } else {
                    errorMessage = std::string("Unexpected operator");
                    state = PARSER_ERROR;
                    break;
                  }
                default:
                  errorMessage = std::string("Unexpected token");
                  state = PARSER_ERROR;
              }
              break;
            default:
              errorMessage = std::string("Unknown token");
              state = PARSER_ERROR;
          }
          break;
        case PARSER_ERROR:
          throw ParserException(errorMessage);
        default:
          errorMessage = std::string("Parser in unknown state");
          state = PARSER_ERROR;
      }
    }
  }

  void Parser::fillTokenBuffer() {
    while(tokenBuffer.size() < 3) {
      Token * token = tokenSource->nextToken();
      tokenBuffer.push_back(token);
    }
  }
}
