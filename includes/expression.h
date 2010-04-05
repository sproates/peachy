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
      void setLValue(std::string identifier);
      void setRValue(Expression * e);

    protected:

      Expression(Log * logger);
      Log * logger;
      ExpressionType expressionType;

      std::string lValue;
      Expression * rValue;

    private:

      Expression();
      Expression(const Expression & expression);
      Expression & operator = (const Expression & expression);
  };
}

#endif
