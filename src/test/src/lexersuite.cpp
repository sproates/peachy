#include "lexersuite.h"

#include <iostream>
#include <string>

#include "lexer.h"
#include "lexerexception.h"
#include "log.h"
#include "nullostream.h"
#include "scriptsource.h"
#include "stringscriptsource.h"
#include "testsuite.h"
#include "token.h"
#include "tokenfactory.h"

namespace peachy {

  namespace test {

    LexerSuite::~LexerSuite() {
      teardown();
    }

    void LexerSuite::startup() {
      ostream = new NullOStream();
      logger = new Log(ostream);
      tokenFactory = new TokenFactory(logger, logger);
    }

    void LexerSuite::teardown() {
      delete token;
      delete lexer;
      delete scriptSource;
      delete tokenFactory;
      delete logger;
    }

    void LexerSuite::run() {

      scriptSource = new StringScriptSource(logger, std::string(""));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_EOF, "First token is TOKEN_EOF");

      scriptSource = new StringScriptSource(logger, std::string("a"));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_IDENTIFIER, "First token is TOKEN_IDENTIFIER");
      ASSERT_EQUALS(token->getData().compare(std::string("a")) == 0, "First token is 'a'");
      
      scriptSource = new StringScriptSource(logger, std::string("<-"));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_OPERATOR, "First token is TOKEN_OPERATOR");
      ASSERT_EQUALS(token->getData().compare(std::string("<-")) == 0, "First token is <-");

      scriptSource = new StringScriptSource(logger, std::string("="));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_OPERATOR, "First token is TOKEN_OPERATOR");
      ASSERT_EQUALS(token->getData().compare(std::string("=")) == 0, "First token is =");

      scriptSource = new StringScriptSource(logger, std::string(">="));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_OPERATOR, "First token is TOKEN_OPERATOR");
      ASSERT_EQUALS(token->getData().compare(std::string(">=")) == 0, "First token is >=");

      scriptSource = new StringScriptSource(logger, std::string("<="));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_OPERATOR, "First token is TOKEN_OPERATOR");
      ASSERT_EQUALS(token->getData().compare(std::string("<=")) == 0, "First token is <=");

      scriptSource = new StringScriptSource(logger, std::string(">"));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_OPERATOR, "First token is TOKEN_OPERATOR");
      ASSERT_EQUALS(token->getData().compare(std::string(">")) == 0, "First token is >");

      scriptSource = new StringScriptSource(logger, std::string("<"));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_OPERATOR, "First token is TOKEN_OPERATOR");
      ASSERT_EQUALS(token->getData().compare(std::string("<")) == 0, "First token is <");

      scriptSource = new StringScriptSource(logger, std::string("+"));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_OPERATOR, "First token is TOKEN_OPERATOR");
      ASSERT_EQUALS(token->getData().compare(std::string("+")) == 0, "First token is +");

      scriptSource = new StringScriptSource(logger, std::string("-"));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_OPERATOR, "First token is TOKEN_OPERATOR");
      ASSERT_EQUALS(token->getData().compare(std::string("-")) == 0, "First token is -");

      scriptSource = new StringScriptSource(logger, std::string("|"));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_OPERATOR, "First token is TOKEN_OPERATOR");
      ASSERT_EQUALS(token->getData().compare(std::string("|")) == 0, "First token is |");

      scriptSource = new StringScriptSource(logger, std::string("&"));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_OPERATOR, "First token is TOKEN_OPERATOR");
      ASSERT_EQUALS(token->getData().compare(std::string("&")) == 0, "First token is &");

      scriptSource = new StringScriptSource(logger, std::string("while"));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_KEYWORD, "First token is TOKEN_KEYWORD");
      ASSERT_EQUALS(token->getData().compare(std::string("while")) == 0, "First token is while");

      scriptSource = new StringScriptSource(logger, std::string("for"));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_KEYWORD, "First token is TOKEN_KEYWORD");
      ASSERT_EQUALS(token->getData().compare(std::string("for")) == 0, "First token is for");

      scriptSource = new StringScriptSource(logger, std::string("return"));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_KEYWORD, "First token is TOKEN_KEYWORD");
      ASSERT_EQUALS(token->getData().compare(std::string("return")) == 0, "First token is return");

      scriptSource = new StringScriptSource(logger, std::string("673"));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_INTEGER, "First token is TOKEN_INTEGER");
      ASSERT_EQUALS(token->getData().compare(std::string("673")) == 0, "First token is 673");

      scriptSource = new StringScriptSource(logger, std::string("5"));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_INTEGER, "First token is TOKEN_INTEGER");
      ASSERT_EQUALS(token->getData().compare(std::string("5")) == 0, "First token is 5");

      scriptSource = new StringScriptSource(logger, std::string("-1"));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_INTEGER, "First token is TOKEN_INTEGER");
      ASSERT_EQUALS(token->getData().compare(std::string("-1")) == 0, "First token is -1");

      scriptSource = new StringScriptSource(logger, std::string("-9011"));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_INTEGER, "First token is TOKEN_INTEGER");
      ASSERT_EQUALS(token->getData().compare(std::string("-9011")) == 0, "First token is -9011");

      scriptSource = new StringScriptSource(logger, std::string("("));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_LEFT_PARENTHESIS, "First token is TOKEN_LEFT_PARENTHESIS");

      scriptSource = new StringScriptSource(logger, std::string(")"));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_RIGHT_PARENTHESIS, "First token is TOKEN_RIGHT_PARENTHESIS");

      scriptSource = new StringScriptSource(logger, std::string("{"));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_LEFT_BRACE, "First token is TOKEN_LEFT_BRACE");

      scriptSource = new StringScriptSource(logger, std::string("}"));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_RIGHT_BRACE, "First token is TOKEN_RIGHT_BRACE");

      scriptSource = new StringScriptSource(logger, std::string("["));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_LEFT_BRACKET, "First token is TOKEN_LEFT_BRACKET");

      scriptSource = new StringScriptSource(logger, std::string("]"));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_RIGHT_BRACKET, "First token is TOKEN_RIGHT_BRACKET");

      scriptSource = new StringScriptSource(logger, std::string(":"));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_COLON, "First token is TOKEN_COLON");

      scriptSource = new StringScriptSource(logger, std::string("#comment"));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_COMMENT_LINE, "First token is TOKEN_COMMENT_LINE");
      ASSERT_EQUALS(token->getData().compare(std::string("comment")) == 0, "First token is 'comment'");

      scriptSource = new StringScriptSource(logger, std::string("a <- 673 + 5"));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_IDENTIFIER, "First token is TOKEN_IDENTIFIER");
      ASSERT_EQUALS(token->getData().compare(std::string("a")) == 0, "First token is 'a'");
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_OPERATOR, "Next token is TOKEN_OPERATOR");
      ASSERT_EQUALS(token->getData().compare(std::string("<-")) == 0, "Next token is <-");
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_INTEGER, "Next token is TOKEN_INTEGER");
      ASSERT_EQUALS(token->getData().compare(std::string("673")) == 0, "Next token is 673");
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_OPERATOR, "Next token is TOKEN_OPERATOR");
      ASSERT_EQUALS(token->getData().compare(std::string("+")) == 0, "Next token is +");
      token = lexer->nextToken();
      ASSERT_EQUALS(token->getTokenType() == TOKEN_INTEGER, "Next token is TOKEN_INTEGER");
      ASSERT_EQUALS(token->getData().compare(std::string("5")) == 0, "Next token is 5");

      scriptSource = new StringScriptSource(logger, std::string("^"));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      ASSERT_THROWS(token = lexer->nextToken(), LexerException, "^ is an invalid token");

      scriptSource = new StringScriptSource(logger, std::string("@"));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      ASSERT_THROWS(token = lexer->nextToken(), LexerException, "@ is an invalid token");

      scriptSource = new StringScriptSource(logger, std::string("£"));
      lexer = new Lexer(logger, tokenFactory, scriptSource);
      ASSERT_THROWS(token = lexer->nextToken(), LexerException, "£ is an invalid token");
    }
  }
}
