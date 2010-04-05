#ifndef PEACHY_EXPRESSION_H
#define PEACHY_EXPRESSION_H

#include <string>

#include "expressiontype.h"

namespace peachy {

  class Log;

  class Expression {

    public:

      virtual ~Expression();
      ExpressionType getExpressionType();
      void setLValue(Expression * e);
      void setRValue(Expression * e);
      std::string toString();
      Expression(const Expression & e);
      Expression & operator = (const Expression & e);
      Expression * getLValue();
      Expression * getRValue();

    protected:

      Expression(Log * logger);
      Log * logger;
      ExpressionType expressionType;

      Expression * lValue;
      Expression * rValue;

    private:

      Expression();
  };
}

#endif
