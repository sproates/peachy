#ifndef PEACHY_TEST_EXPRESSIONFACTORYSUITE_H
#define PEACHY_TEST_EXPRESSIONFACTORYSUITE_H

#include "additionexpression.h"
#include "assignmentexpression.h"
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

        AdditionExpression * additionExpression;
        AssignmentExpression * assignmentExpression;
        Expression * expression;
        ExpressionFactory * expressionFactory;
        Log * logger;
        NullOStream * ostream;
    };
  }
}

#endif
