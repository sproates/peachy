#include "peachyparser.h"

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

  PeachyParser::~PeachyParser() {
    logger->debug("PeachyParser destructor");
  }

  std::auto_ptr<Expression> PeachyParser::nextExpression() {
    logger->debug("PeachyParser::nextExpression()");
    Expression * expression = expressionFactory->createQuitExpression();
    return std::auto_ptr<Expression> (expression);
    /*
    std::auto_ptr<Token> token;
    while(true) {
      switch(state) {
        case PARSER_NEED_TOKEN:
          try {
            token = tokenSource->nextToken();
          } catch(LexerException & e) {
            logger->debug(std::string("Lexical error: ").append(e.what()));
            return;
          } catch(...) {
            logger->debug("Unknown exception thrown by TokenSource");
            return;
          }
          setState(PARSER_DEFAULT);
          switch(token.get()->getTokenType()) {
            case TOKEN_EOF:
              logger->debug("TOKEN_EOF encountered");
              return;
            case TOKEN_COMMENT_LINE:
              logger->debug("TOKEN_COMMENT_LINE encountered");
              logger->debug(token->toString());
              setState(PARSER_NEED_TOKEN);
              break;
            case TOKEN_IDENTIFIER:
              logger->debug("TOKEN_IDENTIFIER encountered");
              logger->debug(token->toString());
              setState(PARSER_NEED_TOKEN);
              break;
            case TOKEN_INTEGER:
              logger->debug("TOKEN_INTEGER encountered");
              logger->debug(token->toString());
              setState(PARSER_NEED_TOKEN);
              break;
            case TOKEN_KEYWORD:
              logger->debug("TOKEN_KEYWORD encountered");
              logger->debug(token->toString());
              setState(PARSER_NEED_TOKEN);
              break;
            case TOKEN_NUMBER:
              logger->debug("TOKEN_NUMBER encountered");
              logger->debug(token->toString());
              setState(PARSER_NEED_TOKEN);
              break;
            case TOKEN_OPERATOR:
              logger->debug("TOKEN_OPERATOR encountered");
              logger->debug(token->toString());
              setState(PARSER_NEED_TOKEN);
              break;
            case TOKEN_STRING:
              logger->debug("TOKEN_STRING encountered");
              logger->debug(token->toString());
              setState(PARSER_NEED_TOKEN);
              break;
            default:
              logger->debug("Unknown token encountered");
              throw ParserException("Unknown token encountered");
          }
        break;
        case PARSER_ERROR:
          logger->debug("In state PARSER_ERROR");
          throw ParserException("Parser error");
        default:
          logger->debug("Unknown state");
          setState(PARSER_ERROR);
      }
    }
    */
  }

  ParserState PeachyParser::getState() {
    logger->debug("PeachyParser::getState()");
    return state;
  }

  void PeachyParser::setState(ParserState state) {
    logger->debug("PeachyParser::setState()");
    this->state = state;
  }
}
