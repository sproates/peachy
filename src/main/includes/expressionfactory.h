#ifndef PEACHY_EXPRESSIONFACTORY_H
#define PEACHY_EXPRESSIONFACTORY_H

namespace peachy {

  class AdditionExpression;
  class AssignmentExpression;
  class BooleanLiteralExpression;
  class Expression;
  class IntLiteralExpression;
  class Log;
  class QuitExpression;
  class StringLiteralExpression;
  class VariableExpression;

  class ExpressionFactory {

    public:

      ExpressionFactory(Log * logger, Log * expressionLogger);
      virtual ~ExpressionFactory();

      AdditionExpression * createAdditionExpression();
      AdditionExpression * createAdditionExpression(Log * logger);
      AssignmentExpression * createAssignmentExpression();
      AssignmentExpression * createAssignmentExpression(Log * logger);
      BooleanLiteralExpression * createBooleanLiteralExpression();
      BooleanLiteralExpression * createBooleanLiteralExpression(Log * logger);
      IntLiteralExpression * createIntLiteralExpression();
      IntLiteralExpression * createIntLiteralExpression(Log * logger);
      QuitExpression * createQuitExpression();
      QuitExpression * createQuitExpression(Log * logger);
      StringLiteralExpression * createStringLiteralExpression();
      StringLiteralExpression * createStringLiteralExpression(Log * logger);
      VariableExpression * createVariableExpression();
      VariableExpression * createVariableExpression(Log * logger);

    protected:

      Log * logger;
      Log * expressionLogger;

    private:

      ExpressionFactory();
      ExpressionFactory(const ExpressionFactory & expressionFactory);
      ExpressionFactory & operator = (const ExpressionFactory & expressionFactory);
  };
}

#endif
