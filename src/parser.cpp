#include "parser.h"

#include <memory>

#include "expression.h"
#include "expressionfactory.h"
#include "lexerexception.h"
#include "log.h"
#include "parserexception.h"
#include "parserstate.h"
#include "quitexpression.h"
#include "token.h"
#include "tokensource.h"

namespace peachy {

  Parser::~Parser() {
    logger->debug("Parser destructor");
  }

  std::auto_ptr<Expression> Parser::nextExpression() {
    logger->debug("Parser::nextExpression()");

    Expression * expression;
    std::auto_ptr<Token> currentToken;
    bool gotExpression = false;

    while(!gotExpression) {
      switch(state) {
        case PARSER_NEED_TOKEN:
          logger->debug("In state PARSER_NEED_TOKEN");
          currentToken = tokenSource->nextToken();
          setState(PARSER_DEFAULT);
          break;
        case PARSER_DEFAULT:
          logger->debug("In state PARSER_DEFAULT");
          switch(currentToken.get()->getTokenType()) {
            case TOKEN_EOF:
              logger->debug("Current token is TOKEN_EOF");
              gotExpression = true;
              expression = expressionFactory->createQuitExpression();
              break;
            case TOKEN_IDENTIFIER:
              logger->debug("Current token is TOKEN_IDENTIFIER");
              setState(PARSER_NEED_TOKEN);
              break;
            case TOKEN_OPERATOR:
              logger->debug("Current token is TOKEN_OPERATOR");
              setState(PARSER_NEED_TOKEN);
              break;
            case TOKEN_STRING:
              logger->debug("current token is TOKEN_STRING");
              setState(PARSER_NEED_TOKEN);
              break;
            default:
              logger->debug("Unknown token type");
              errorMessage = std::string("Unknown token type encountered");
              setState(PARSER_ERROR);
          }
          break;
        case PARSER_ERROR:
          logger->debug("In state PARSER_ERROR");
          throw ParserException(errorMessage);
        default:
          logger->debug("Unknown state");
          errorMessage = std::string("Parser in unknown state");
          setState(PARSER_ERROR);
      }      
    }

    return std::auto_ptr<Expression> (expression);
  }

  ParserState Parser::getState() {
    logger->debug("Parser::getState()");
    return state;
  }

  void Parser::setState(ParserState state) {
    logger->debug("Parser::setState()");
    this->state = state;
  }
}
