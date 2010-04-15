#ifndef PEACHY_VALUEEXPRESSION_H
#define PEACHY_VALUEEXPRESSION_H

#include "expression.h"
#include "expressiontype.h"
#include "log.h"

namespace peachy {

  class Object;

  class ValueExpression : public Expression {

    public:

      ValueExpression(Log * logger) : Expression(logger) {
        this->expressionType = EXPRESSION_VALUE;
      }

      ValueExpression(Log * logger, Object * value) : Expression(logger) {
        this->expressionType = EXPRESSION_VALUE;
        this->setValue(value);
      }

      virtual ~ValueExpression();

      Object * getValue();
      void setValue(Object * value);
      std::string toString();

    protected:

      Object * value;
  };
}

#endif
