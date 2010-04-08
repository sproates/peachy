#ifndef PEACHY_INTLITERALEXPRESSION_H
#define PEACHY_INTLITERALEXPRESSION_H

#include "expression.h"
#include "expressiontype.h"
#include "log.h"

namespace peachy {

  class IntLiteralExpression : public Expression {

    public:

      IntLiteralExpression(Log * logger) : Expression(logger) {
        logger->debug("IntLiteralExpression constructor");
        this->expressionType = EXPRESSION_INT_LITERAL;
      }
      virtual ~IntLiteralExpression();
      void setValue(int value);
      int getValue();

    protected:

      int value;
  };
}

#endif
