#ifndef PEACHY_TEST_EXPRESSIONFACTORYSUITE_H
#define PEACHY_TEST_EXPRESSIONFACTORYSUITE_H

#include "additionexpression.h"
#include "assignmentexpression.h"
#include "booleanliteralexpression.h"
#include "expression.h"
#include "expressionfactory.h"
#include "intliteralexpression.h"
#include "log.h"
#include "nullostream.h"
#include "quitexpression.h"
#include "stringliteralexpression.h"
#include "testsuite.h"
#include "variableexpression.h"

namespace peachy {

  namespace test {

    class ExpressionFactorySuite : public TestSuite {

    public:

        ExpressionFactorySuite() : TestSuite() {
          startup();
        }

        ~ExpressionFactorySuite();

      private:

        void startup();
        void teardown();
        void run();

        AdditionExpression * addition;
        AssignmentExpression * assignment;
        BooleanLiteralExpression * booleanLiteral;
        QuitExpression * quit;
        IntLiteralExpression * intLiteral;
        StringLiteralExpression * stringLiteral;
        VariableExpression * variable;
        
        Expression * expression;
        ExpressionFactory * expressionFactory;
        Log * logger;
        NullOStream * ostream;
        
    };
  }
}

#endif
