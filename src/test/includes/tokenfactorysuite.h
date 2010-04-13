#ifndef PEACHY_TEST_TOKENFACTORYSUITE_H
#define PEACHY_TEST_TOKENFACTORYSUITE_H

#include "log.h"
#include "nullostream.h"
#include "testsuite.h"
#include "token.h"
#include "tokenfactory.h"

namespace peachy {

  namespace test {

    class TokenFactorySuite : public TestSuite {

      public:

        TokenFactorySuite() : TestSuite() {
          startup();
        }

        ~TokenFactorySuite();

      private:

        void startup();
        void teardown();
        void run();

        Log * logger;
        NullOStream * ostream;
        Token * token;
        TokenFactory * tokenFactory;
    };
  }
}

#endif
