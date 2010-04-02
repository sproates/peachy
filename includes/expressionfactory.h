#ifndef PEACHY_EXPRESSIONFACTORY_H
#define PEACHY_EXPRESSIONFACTORY_H

namespace peachy {

  class Expression;
  class Log;

  class ExpressionFactory {

    public:

      ExpressionFactory(Log * logger, Log * expressionLogger);
      virtual ~ExpressionFactory();
      Expression * createExpression();
      Expression * createExpression(Log * logger);

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
