#ifndef PEACHY_BOOLEANEXPRESSION_H
#define PEACHY_BOOLEANEXPRESSION_H

#include <string>

#include "expression.h"
#include "expressiontype.h"
#include "log.h"

namespace peachy {

  class BooleanExpression : public Expression {

    public:

      BooleanExpression(Log * logger) : Expression(logger) {
        logger->debug("BooleanExpression constructor");
        this->expressionType = EXPRESSION_BOOLEAN;
      }

      virtual ~BooleanExpression();
      Expression * getLValue();
      Expression * getRValue();
      void setLValue(Expression * e);
      void setRValue(Expression * e);
      std::string toString();

    protected:

      Expression * lValue;
      Expression * rValue;
  };
}

#endif
