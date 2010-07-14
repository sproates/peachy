#include "parser.h"

#include <cstdlib>

#include "additionexpression.h"
#include "assignmentexpression.h"
#include "booleanexpression.h"
#include "booleanliteralexpression.h"
#include "comparisontype.h"
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
        case PARSER_NEED_TOKEN: {
          if(tokenBuffer.size() > 0) {
            state = PARSER_DEFAULT;
            break;
          }
          return expressionFactory->createQuitExpression();
        } case PARSER_DEFAULT: {
          switch(tokenBuffer.front()->getTokenType()) {
            case TOKEN_EOF: {
              return expressionFactory->createQuitExpression();
            } case TOKEN_IDENTIFIER: {
              logger->debug("in token identifier");
              VariableExpression * ve =
                expressionFactory->createVariableExpression();
              ve->setVariableName(tokenBuffer[0]->getData());
              tokenBuffer.pop_front();
              switch(tokenBuffer[0]->getTokenType()) {
                case TOKEN_EOF:
                case TOKEN_IDENTIFIER:
                case TOKEN_INTEGER:
                case TOKEN_KEYWORD:
                case TOKEN_STRING: {
                  logger->debug("Nothing more to do for current identifier");
                  return ve;
                } case TOKEN_OPERATOR: {
                  logger->debug("Operator follows identifier");
                  if(tokenBuffer[0]->getData().compare("<-") == 0) {
                    AssignmentExpression * ae =
                      expressionFactory->createAssignmentExpression();
                    ae->setLValue(ve);
                    tokenBuffer.pop_front();
                    ae->setRValue(nextExpression(PARSER_DEFAULT));
                    logger->debug(ae->toString());
                    return ae;
                  } else if(tokenBuffer[0]->getData().compare("->") == 0) {
                    AssignmentExpression * ae =
                      expressionFactory->createAssignmentExpression();
                    ae->setRValue(ve);
                    tokenBuffer.pop_front();
                    ae->setLValue(nextExpression(PARSER_DEFAULT));
                    logger->debug(ae->toString());
                    return ae;
                  } else if(tokenBuffer[0]->getData().compare("+") == 0) {
                    AdditionExpression * addEx =
                      expressionFactory->createAdditionExpression();
                    addEx->setLValue(ve);
                    tokenBuffer.pop_front();
                    addEx->setRValue(nextExpression(PARSER_DEFAULT));
                    logger->debug(addEx->toString());
                    return addEx;
                  } else if(tokenBuffer[0]->getData().compare("<") == 0) {
                    logger->debug("less than following identifier");
                    BooleanExpression * boolEx =
                      expressionFactory->createBooleanExpression();
                    boolEx->setLValue(ve);
                    boolEx->setComparisonType(COMPARISON_LESS_THAN);
                    tokenBuffer.pop_front();
                    boolEx->setRValue(nextExpression(PARSER_DEFAULT));
                    logger->debug("boolean expression complete");
                    return boolEx;
                    break;
                  } else {
                    errorMessage = std::string("Unexpected operator following variable ").append(ve->getVariableName());
                    state = PARSER_ERROR;
                    break;
                  }
                  break;
                } default: {
                  errorMessage = std::string("Unexpected token type: ").append(tokenBuffer[0]->toString());;
                  state = PARSER_ERROR;
                }
              }
              break;
            } case TOKEN_INTEGER: {
              logger->debug("in token integer");
              IntLiteralExpression * ile =
                expressionFactory->createIntLiteralExpression();
              ile->setValue(atoi(tokenBuffer.front()->getData().c_str()));
              tokenBuffer.pop_front();
              switch(tokenBuffer[0]->getTokenType()) {
                case TOKEN_EOF:
                case TOKEN_IDENTIFIER:
                case TOKEN_INTEGER:
                case TOKEN_KEYWORD:
                case TOKEN_LEFT_PARENTHESIS:
                case TOKEN_RIGHT_PARENTHESIS: {
                  logger->debug("Nothing more to do with current integer");
                  return ile;
                } case TOKEN_OPERATOR: {
                  logger->debug("Operator follows integer");
                  if(tokenBuffer[0]->getData().compare("+") == 0) {
                    AdditionExpression * addEx =
                      expressionFactory->createAdditionExpression();
                    addEx->setLValue(ile);
                    tokenBuffer.pop_front();
                    addEx->setRValue(nextExpression(PARSER_DEFAULT));
                    logger->debug(addEx->toString());
                    return addEx;
                  } else if(tokenBuffer[0]->getData().compare("<-") == 0 ) {
                    errorMessage = std::string("Invalid assignment");
                    state = PARSER_ERROR;
                    break;
                  } else if(tokenBuffer[0]->getData().compare("->") == 0 ) {
                    AssignmentExpression * ae =
                      expressionFactory->createAssignmentExpression();
                    ae->setRValue(ile);
                    tokenBuffer.pop_front();
                    Expression * lValue = nextExpression(PARSER_DEFAULT);
                    ae->setLValue(lValue);
                    logger->debug(ae->toString());
                    return ae;
                  } else {
                    errorMessage = std::string("Unexpected operator: ").append(tokenBuffer[0]->toString());
                    state = PARSER_ERROR;
                    break;
                  }
                } default: {
                  errorMessage = std::string("Unexpected token: ").append(tokenBuffer[0]->toString());
                  state = PARSER_ERROR;
                }
              }
              break;
            } case TOKEN_OPERATOR: {
              logger->debug("In token operator");
              errorMessage = std::string("Unexpected operator: ").append(tokenBuffer.front()->toString());
              state = PARSER_ERROR;
              break;
            } case TOKEN_STRING: {
              logger->debug("in token string");
              StringLiteralExpression * sle =
                expressionFactory->createStringLiteralExpression();
              sle->setStringValue(tokenBuffer.front()->getData());
              tokenBuffer.pop_front();
              switch(tokenBuffer[0]->getTokenType()) {
                case TOKEN_EOF:
                case TOKEN_IDENTIFIER:
                case TOKEN_INTEGER:
                case TOKEN_KEYWORD:
                case TOKEN_STRING: {
                  logger->debug("Nothing more to do with current string");
                  return sle;
                } case TOKEN_OPERATOR: {
                  logger->debug("Operator follows string");
                  if(tokenBuffer[0]->getData().compare("+") == 0) {
                    AdditionExpression * addEx =
                      expressionFactory->createAdditionExpression();
                    addEx->setLValue(sle);
                    tokenBuffer.pop_front();
                    addEx->setRValue(nextExpression(PARSER_DEFAULT));
                    logger->debug(addEx->toString());
                    return addEx;
                  } else if(tokenBuffer[0]->getData().compare("->") == 0) {
                    tokenBuffer.pop_front();
                    AssignmentExpression * ae =
                      expressionFactory->createAssignmentExpression();
                    ae->setRValue(sle);
                    ae->setLValue(nextExpression(PARSER_DEFAULT));
                    return ae;
                  } else {
                    errorMessage = std::string("Unexpected operator");
                    state = PARSER_ERROR;
                    break;
                  }
                } default: {
                  errorMessage = std::string("Unexpected token: ").append(tokenBuffer[0]->toString());
                  state = PARSER_ERROR;
                }
              }
              break;
            } case TOKEN_KEYWORD: {
              logger->debug("in token keyword");
              if(tokenBuffer[0]->getData().compare("while") == 0) {
                logger->debug("while keyword encountered");
                tokenBuffer.pop_front();
                switch(tokenBuffer[0]->getTokenType()) {
                  case TOKEN_LEFT_PARENTHESIS: {
                    logger->debug("Next token after while is left paren");
                    tokenBuffer.pop_front();
                    logger->debug("recursing for while loop condition");
                    Expression * condition = nextExpression(PARSER_DEFAULT);
                    logger->debug("finished recursing for while loop condition");
                    if(tokenBuffer[0]->getTokenType() != TOKEN_RIGHT_PARENTHESIS) {
                      errorMessage = std::string("Mismatched parentheses");
                      state = PARSER_ERROR;
                      break;
                    } else {
                      return condition;
                    }
                  } default: {
                    logger->debug("next token after while should be left paren but isnt");
                    errorMessage = std::string("Expected TOKEN_LEFT_PARENTHESIS following while, got: ").append(tokenBuffer[0]->toString());
                    state = PARSER_ERROR;
                  }
                }
                break;
              } else if(tokenBuffer[0]->getData().compare("true") == 0) {
                logger->debug("true keyword encountered");
                tokenBuffer.pop_front();
                BooleanLiteralExpression * trueExp =
                  expressionFactory->createBooleanLiteralExpression();
                trueExp->setValue(true);
                return trueExp;
              } else if(tokenBuffer[0]->getData().compare("false") == 0) {
                logger->debug("false keyword encountered");
                tokenBuffer.pop_front();
                BooleanLiteralExpression * falseExp =
                  expressionFactory->createBooleanLiteralExpression();
                falseExp->setValue(false);
                return falseExp;
              } else {
                errorMessage = std::string("Unable to handle that keyword");
                state = PARSER_ERROR;
                break;
              }
            } default: {
              errorMessage = std::string("Unknown token");
              logger->debug("Unknown token follows:");
              logger->debug(tokenBuffer.front()->toString());
              state = PARSER_ERROR;
            }
          }
        } case PARSER_ERROR: {
          throw ParserException(errorMessage);
        } default: {
          errorMessage = std::string("Parser in unknown state");
          state = PARSER_ERROR;
        }
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
