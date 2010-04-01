#include "peachyparser.h"

#include <memory>

#include "lexerexception.h"
#include "log.h"
#include "parserexception.h"
#include "token.h"
#include "tokensource.h"

namespace peachy {

  PeachyParser::~PeachyParser() {
    logger->debug("PeachyParser destructor");
  }

  void PeachyParser::parse() {
    logger->debug("PeachyParser::parse()");
    std::auto_ptr<Token> token;
    while(true) {
      try {
        token = tokenSource->nextToken();
      } catch(LexerException & e) {
        logger->debug(std::string("Lexical error: ").append(e.what()));
        return;
      } catch(...) {
        logger->debug("Unknown exception thrown by TokenSource");
        return;
      }
      switch(token.get()->getTokenType()) {
        case TOKEN_EOF:
          logger->debug("TOKEN_EOF encountered");
          return;
        case TOKEN_COMMENT_LINE:
          logger->debug("TOKEN_COMMENT_LINE encountered");
          logger->debug(token->toString());
          break;
        case TOKEN_IDENTIFIER:
          logger->debug("TOKEN_IDENTIFIER encountered");
          logger->debug(token->toString());
          break;
        case TOKEN_INTEGER:
          logger->debug("TOKEN_INTEGER encountered");
          logger->debug(token->toString());
          break;
        case TOKEN_KEYWORD:
          logger->debug("TOKEN_KEYWORD encountered");
          logger->debug(token->toString());
          break;
        case TOKEN_NUMBER:
          logger->debug("TOKEN_NUMBER encountered");
          logger->debug(token->toString());
          break;
        case TOKEN_OPERATOR:
          logger->debug("TOKEN_OPERATOR encountered");
          logger->debug(token->toString());
          break;
        case TOKEN_STRING:
          logger->debug("TOKEN_STRING encountered");
          logger->debug(token->toString());
          break;
        default:
          logger->debug("Unknown token encountered");
          throw ParserException("Unknown token encountered");
      }
    }
  }
}
