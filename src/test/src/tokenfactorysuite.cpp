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
    }
  }
}
