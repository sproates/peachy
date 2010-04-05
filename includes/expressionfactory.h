#ifndef PEACHY_EXPRESSIONFACTORY_H
#define PEACHY_EXPRESSIONFACTORY_H

namespace peachy {

  class AssignmentExpression;
  class Expression;
  class Log;
  class QuitExpression;

  class ExpressionFactory {

    public:

      ExpressionFactory(Log * logger, Log * expressionLogger);
      virtual ~ExpressionFactory();

      AssignmentExpression * createAssignmentExpression();
      AssignmentExpression * createAssignmentExpression(Log * logger);
      QuitExpression * createQuitExpression();
      QuitExpression * createQuitExpression(Log * logger);

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
