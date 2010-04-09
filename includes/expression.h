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
      std::string toString();
      Expression(const Expression & e);
      Expression & operator = (const Expression & e);
      bool hasValue();

    protected:

      Expression(Log * logger);
      Log * logger;
      ExpressionType expressionType;
      bool gotValue;

    private:

      Expression();
  };
}

#endif
