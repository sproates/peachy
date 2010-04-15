#ifndef PEACHY_ADDITIONEXPRESSION_H
#define PEACHY_ADDITIONEXPRESSION_H

#include <string>

#include "expression.h"
#include "expressiontype.h"
#include "log.h"

namespace peachy {

  class AdditionExpression : public Expression {

    public:

      AdditionExpression(Log * logger) : Expression(logger) {
        this->expressionType = EXPRESSION_ADDITION;
      }
      virtual ~AdditionExpression();
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
