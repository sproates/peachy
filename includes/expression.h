#ifndef PEACHY_EXPRESSION_H
#define PEACHY_EXPRESSION_H

#include "expressiontype.h"

namespace peachy {

  class Log;

  class Expression {

    public:

      virtual ~Expression();
      ExpressionType getExpressionType();

    protected:

      Expression(Log * logger);
      Log * logger;
      ExpressionType expressionType;

    private:

      Expression();
      Expression(const Expression & expression);
      Expression & operator = (const Expression & expression);
  };
}

#endif
