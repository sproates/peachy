#ifndef PEACHY_BOOLEANEXPRESSION_H
#define PEACHY_BOOLEANEXPRESSION_H

#include <string>

#include "comparisontype.h"
#include "expression.h"
#include "expressiontype.h"
#include "log.h"

namespace peachy {

  class BooleanExpression : public Expression {

    public:

      BooleanExpression(Log * logger) : Expression(logger) {
        logger->debug("BooleanExpression constructor");
        this->expressionType = EXPRESSION_BOOLEAN;
        this->comparisonType = COMPARISON_NONE;
      }

      virtual ~BooleanExpression();
      Expression * getLValue();
      Expression * getRValue();
      ComparisonType getComparisonType();
      void setLValue(Expression * e);
      void setRValue(Expression * e);
      void setComparisonType(ComparisonType c);
      std::string toString();

    protected:

      Expression * lValue;
      Expression * rValue;
      ComparisonType comparisonType;
  };
}

#endif
