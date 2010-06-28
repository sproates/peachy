#include "expressionfactorysuite.h"

#include <string>

#include "additionexpression.h"
#include "assignmentexpression.h"
#include "booleanliteralexpression.h"
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
      addition = new AdditionExpression(logger);
      assignment = new AssignmentExpression(logger);
      booleanLiteral = new BooleanLiteralExpression(logger);
      intLiteral = new IntLiteralExpression(logger);
      quit = new QuitExpression(logger);
      stringLiteral = new StringLiteralExpression(logger);
      variable = new VariableExpression(logger);
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
      ASSERT_INSTANCE(expression, addition, "Expression type correct");

      expression = expressionFactory->createAdditionExpression(logger);
      ASSERT_EQUALS(expression->getExpressionType() == EXPRESSION_ADDITION, "Expression type correct");
      ASSERT_INSTANCE(expression, addition, "Expression type correct");

      expression = expressionFactory->createAssignmentExpression();
      ASSERT_EQUALS(expression->getExpressionType() == EXPRESSION_ASSIGNMENT, "Expression type correct");
      ASSERT_INSTANCE(expression, assignment, "Expression type correct");

      expression = expressionFactory->createAssignmentExpression(logger);
      ASSERT_EQUALS(expression->getExpressionType() == EXPRESSION_ASSIGNMENT, "Expression type correct");
      ASSERT_INSTANCE(expression, assignment, "Expression type correct");

      expression = expressionFactory->createBooleanLiteralExpression();
      ASSERT_EQUALS(expression->getExpressionType() == EXPRESSION_BOOLEAN_LITERAL, "Expression type correct");
      ASSERT_INSTANCE(expression, booleanLiteral, "Expression type correct");

      expression = expressionFactory->createBooleanLiteralExpression(logger);
      ASSERT_EQUALS(expression->getExpressionType() == EXPRESSION_BOOLEAN_LITERAL, "Expression type correct");
      ASSERT_INSTANCE(expression, booleanLiteral, "Expression type correct");

      expression = expressionFactory->createIntLiteralExpression();
      ASSERT_EQUALS(expression->getExpressionType() == EXPRESSION_INT_LITERAL, "Expression type correct");
      ASSERT_INSTANCE(expression, intLiteral, "Expression type correct");

      expression = expressionFactory->createIntLiteralExpression(logger);
      ASSERT_EQUALS(expression->getExpressionType() == EXPRESSION_INT_LITERAL, "Expression type correct");
      ASSERT_INSTANCE(expression, intLiteral, "Expression type correct");

      expression = expressionFactory->createQuitExpression();
      ASSERT_EQUALS(expression->getExpressionType() == EXPRESSION_QUIT, "Expression type correct");
      ASSERT_INSTANCE(expression, quit, "Expression type correct");

      expression = expressionFactory->createQuitExpression(logger);
      ASSERT_EQUALS(expression->getExpressionType() == EXPRESSION_QUIT, "Expression type correct");
      ASSERT_INSTANCE(expression, quit, "Expression type correct");

      expression = expressionFactory->createStringLiteralExpression();
      ASSERT_EQUALS(expression->getExpressionType() == EXPRESSION_STRING_LITERAL, "Expression type correct");
      ASSERT_INSTANCE(expression, stringLiteral, "Expression type correct");

      expression = expressionFactory->createStringLiteralExpression(logger);
      ASSERT_EQUALS(expression->getExpressionType() == EXPRESSION_STRING_LITERAL, "Expression type correct");
      ASSERT_INSTANCE(expression, stringLiteral, "Expression type correct");

      expression = expressionFactory->createVariableExpression();
      ASSERT_EQUALS(expression->getExpressionType() == EXPRESSION_VARIABLE, "Expression type correct");
      ASSERT_INSTANCE(expression, variable, "Expression type correct");

      expression = expressionFactory->createVariableExpression(logger);
      ASSERT_EQUALS(expression->getExpressionType() == EXPRESSION_VARIABLE, "Expression type correct");
      ASSERT_INSTANCE(expression, variable, "Expression type correct");
    }
  }
}
