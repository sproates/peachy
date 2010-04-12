#ifndef PEACHY_TEST_EXPRESSIONFACTORYSUITE_H
#define PEACHY_TEST_EXPRESSIONFACTORYSUITE_H

#include "expression.h"
#include "expressionfactory.h"
#include "log.h"
#include "nullostream.h"
#include "testsuite.h"

namespace peachy {

  namespace test {

    class ExpressionFactorySuite : public TestSuite {

    public:

        ExpressionFactorySuite() : TestSuite() {
          startup();
        }

        ~ExpressionFactorySuite();

        void startup();
        void teardown();
        void run();

      protected:

        Expression * expression;
        ExpressionFactory * expressionFactory;
        Log * logger;
        NullOStream * ostream;
    };
  }
}

#endif
