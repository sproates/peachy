#include "tokenfactorysuite.h"

#include <string>

#include "log.h"
#include "nullostream.h"
#include "testsuite.h"
#include "token.h"
#include "tokenfactory.h"

namespace peachy {

  namespace test {

    TokenFactorySuite::~TokenFactorySuite() {
      teardown();
    }

    void TokenFactorySuite::startup() {
      ostream = new NullOStream();
      logger = new Log(ostream);
      tokenFactory = new TokenFactory(logger, logger);
    }

    void TokenFactorySuite::teardown() {
      delete token;
      delete tokenFactory;
      delete logger;
      delete ostream;
    }

    void TokenFactorySuite::run() {
      token = tokenFactory->createToken(TOKEN_COLON);
      ASSERT_EQUALS(token->getTokenType() == TOKEN_COLON, "Token is TOKEN_COLON");
      ASSERT_EQUALS(token->getData().compare(std::string("")) == 0, "Token data is empty");

      token = tokenFactory->createToken(logger, TOKEN_COLON);
      ASSERT_EQUALS(token->getTokenType() == TOKEN_COLON, "Token is TOKEN_COLON");
      ASSERT_EQUALS(token->getData().compare(std::string("")) == 0, "Token data is empty");

      token = tokenFactory->createToken(TOKEN_COMMENT_LINE);
      ASSERT_EQUALS(token->getTokenType() == TOKEN_COMMENT_LINE, "Token is TOKEN_COMMENT_LINE");
      ASSERT_EQUALS(token->getData().compare(std::string("")) == 0, "Token data is empty");

      token = tokenFactory->createToken(logger, TOKEN_COMMENT_LINE);
      ASSERT_EQUALS(token->getTokenType() == TOKEN_COMMENT_LINE, "Token is TOKEN_COMMENT_LINE");
      ASSERT_EQUALS(token->getData().compare(std::string("")) == 0, "Token data is empty");

      token = tokenFactory->createToken(TOKEN_COMMENT_LINE, std::string("a comment"));
      ASSERT_EQUALS(token->getTokenType() == TOKEN_COMMENT_LINE, "Token is TOKEN_COMMENT_LINE");
      ASSERT_EQUALS(token->getData().compare(std::string("a comment")) == 0, "Token data is correct");

      token = tokenFactory->createToken(logger, TOKEN_COMMENT_LINE, std::string("a comment"));
      ASSERT_EQUALS(token->getTokenType() == TOKEN_COMMENT_LINE, "Token is TOKEN_COMMENT_LINE");
      ASSERT_EQUALS(token->getData().compare(std::string("a comment")) == 0, "Token data is correct");

      token = tokenFactory->createToken(TOKEN_EMPTY);
      ASSERT_EQUALS(token->getTokenType() == TOKEN_EMPTY, "Token is TOKEN_EMPTY");
      ASSERT_EQUALS(token->getData().compare(std::string("")) == 0, "Token data is empty");

      token = tokenFactory->createToken(logger, TOKEN_EMPTY);
      ASSERT_EQUALS(token->getTokenType() == TOKEN_EMPTY, "Token is TOKEN_EMPTY");
      ASSERT_EQUALS(token->getData().compare(std::string("")) == 0, "Token data is empty");

      token = tokenFactory->createToken(TOKEN_EOF);
      ASSERT_EQUALS(token->getTokenType() == TOKEN_EOF, "Token is TOKEN_EOF");
      ASSERT_EQUALS(token->getData().compare(std::string("")) == 0, "Token data is empty");

      token = tokenFactory->createToken(logger, TOKEN_EOF);
      ASSERT_EQUALS(token->getTokenType() == TOKEN_EOF, "Token is TOKEN_EMPTY");
      ASSERT_EQUALS(token->getData().compare(std::string("")) == 0, "Token data is empty");

      token = tokenFactory->createToken(TOKEN_IDENTIFIER);
      ASSERT_EQUALS(token->getTokenType() == TOKEN_IDENTIFIER, "Token is TOKEN_IDENTIFIER");
      ASSERT_EQUALS(token->getData().compare(std::string("")) == 0, "Token data is empty");

      token = tokenFactory->createToken(logger, TOKEN_IDENTIFIER);
      ASSERT_EQUALS(token->getTokenType() == TOKEN_IDENTIFIER, "Token is TOKEN_IDENTIFIER");
      ASSERT_EQUALS(token->getData().compare(std::string("")) == 0, "Token data is empty");

      token = tokenFactory->createToken(TOKEN_IDENTIFIER, std::string("abc"));
      ASSERT_EQUALS(token->getTokenType() == TOKEN_IDENTIFIER, "Token is TOKEN_IDENTIFIER");
      ASSERT_EQUALS(token->getData().compare(std::string("abc")) == 0, "Token data is correct");

      token = tokenFactory->createToken(logger, TOKEN_IDENTIFIER, std::string("abc"));
      ASSERT_EQUALS(token->getTokenType() == TOKEN_IDENTIFIER, "Token is TOKEN_IDENTIFIER");
      ASSERT_EQUALS(token->getData().compare(std::string("abc")) == 0, "Token data is correct");

      token = tokenFactory->createToken(TOKEN_IDENTIFIER, std::string("apple_1"));
      ASSERT_EQUALS(token->getTokenType() == TOKEN_IDENTIFIER, "Token is TOKEN_IDENTIFIER");
      ASSERT_EQUALS(token->getData().compare(std::string("apple_1")) == 0, "Token data is correct");

      token = tokenFactory->createToken(logger, TOKEN_IDENTIFIER, std::string("apple_1"));
      ASSERT_EQUALS(token->getTokenType() == TOKEN_IDENTIFIER, "Token is TOKEN_IDENTIFIER");
      ASSERT_EQUALS(token->getData().compare(std::string("apple_1")) == 0, "Token data is correct");

      token = tokenFactory->createToken(TOKEN_INTEGER);
      ASSERT_EQUALS(token->getTokenType() == TOKEN_INTEGER, "Token is TOKEN_INTEGER");
      ASSERT_EQUALS(token->getData().compare(std::string("")) == 0, "Token data is empty");

      token = tokenFactory->createToken(logger, TOKEN_INTEGER);
      ASSERT_EQUALS(token->getTokenType() == TOKEN_INTEGER, "Token is TOKEN_INTEGER");
      ASSERT_EQUALS(token->getData().compare(std::string("")) == 0, "Token data is empty");

      token = tokenFactory->createToken(TOKEN_INTEGER, std::string("1234"));
      ASSERT_EQUALS(token->getTokenType() == TOKEN_INTEGER, "Token is TOKEN_INTEGER");
      ASSERT_EQUALS(token->getData().compare(std::string("1234")) == 0, "Token data is correct");

      token = tokenFactory->createToken(logger, TOKEN_INTEGER, std::string("1234"));
      ASSERT_EQUALS(token->getTokenType() == TOKEN_INTEGER, "Token is TOKEN_INTEGER");
      ASSERT_EQUALS(token->getData().compare(std::string("1234")) == 0, "Token data is correct");

      token = tokenFactory->createToken(TOKEN_INTEGER, std::string("-52"));
      ASSERT_EQUALS(token->getTokenType() == TOKEN_INTEGER, "Token is TOKEN_INTEGER");
      ASSERT_EQUALS(token->getData().compare(std::string("-52")) == 0, "Token data is correct");

      token = tokenFactory->createToken(logger, TOKEN_INTEGER, std::string("-52"));
      ASSERT_EQUALS(token->getTokenType() == TOKEN_INTEGER, "Token is TOKEN_INTEGER");
      ASSERT_EQUALS(token->getData().compare(std::string("-52")) == 0, "Token data is correct");

      token = tokenFactory->createToken(TOKEN_KEYWORD);
      ASSERT_EQUALS(token->getTokenType() == TOKEN_KEYWORD, "Token is TOKEN_KEYWORD");
      ASSERT_EQUALS(token->getData().compare(std::string("")) == 0, "Token data is empty");

      token = tokenFactory->createToken(logger, TOKEN_KEYWORD);
      ASSERT_EQUALS(token->getTokenType() == TOKEN_KEYWORD, "Token is TOKEN_KEYWORD");
      ASSERT_EQUALS(token->getData().compare(std::string("")) == 0, "Token data is empty");

      token = tokenFactory->createToken(TOKEN_KEYWORD, std::string("while"));
      ASSERT_EQUALS(token->getTokenType() == TOKEN_KEYWORD, "Token is TOKEN_KEYWORD");
      ASSERT_EQUALS(token->getData().compare(std::string("while")) == 0, "Token data is empty");

      token = tokenFactory->createToken(logger, TOKEN_KEYWORD, std::string("while"));
      ASSERT_EQUALS(token->getTokenType() == TOKEN_KEYWORD, "Token is TOKEN_KEYWORD");
      ASSERT_EQUALS(token->getData().compare(std::string("while")) == 0, "Token data is empty");

      token = tokenFactory->createToken(TOKEN_KEYWORD, std::string("for"));
      ASSERT_EQUALS(token->getTokenType() == TOKEN_KEYWORD, "Token is TOKEN_KEYWORD");
      ASSERT_EQUALS(token->getData().compare(std::string("for")) == 0, "Token data is empty");

      token = tokenFactory->createToken(logger, TOKEN_KEYWORD, std::string("for"));
      ASSERT_EQUALS(token->getTokenType() == TOKEN_KEYWORD, "Token is TOKEN_KEYWORD");
      ASSERT_EQUALS(token->getData().compare(std::string("for")) == 0, "Token data is empty");
    }
  }
}
