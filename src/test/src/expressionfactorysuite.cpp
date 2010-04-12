#include "expressionfactorysuite.h"

#include <string>

#include "additionexpression.h"
#include "assignmentexpression.h"
#include "expression.h"
#include "expressionfactory.h"
#include "expressiontype.h"
#include "log.h"
#include "nullostream.h"
#include "testsuite.h"

namespace peachy {

  namespace test {

    ExpressionFactorySuite::~ExpressionFactorySuite() {
      teardown();
    }

    void ExpressionFactorySuite::startup() {
      ostream = new NullOStream();
      logger = new Log(ostream);
      expressionFactory = new ExpressionFactory(logger, logger);
      additionExpression = new AdditionExpression(logger);
      assignmentExpression = new AssignmentExpression(logger);
    }

    void ExpressionFactorySuite::teardown() {
      delete expression;
      delete expressionFactory;
      delete logger;
      delete ostream;
    }

    void ExpressionFactorySuite::run() {
      expression = expressionFactory->createAdditionExpression();
      ASSERT_EQUALS(expression->getExpressionType() == EXPRESSION_ADDITION, "Expression type correct");
      ASSERT_INSTANCE(expression, additionExpression, "Expression type correct")
    }
  }
}
