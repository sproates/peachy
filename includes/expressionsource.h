#ifndef PEACHY_EXPRESSIONSOURCE_H
#define PEACHY_EXPRESSIONSOURCE_H

namespace peachy {

  class Expression;
  class ExpressionFactory;
  class Log;
  class TokenSource;

  class ExpressionSource {

    public:

      ExpressionSource(Log * logger, ExpressionFactory * expressionFactory,
        TokenSource * tokenSource);
      virtual ~ExpressionSource();

      virtual Expression * nextExpression() = 0;

    protected:

      Log * logger;
      ExpressionFactory * expressionFactory;
      TokenSource * tokenSource;

    private:

      ExpressionSource();
      ExpressionSource(const ExpressionSource & s);
      ExpressionSource & operator = (const ExpressionSource & s);
  };
}

#endif
