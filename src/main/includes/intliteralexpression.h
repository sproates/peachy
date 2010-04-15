#ifndef PEACHY_INTLITERALEXPRESSION_H
#define PEACHY_INTLITERALEXPRESSION_H

#include <string>

#include "expression.h"
#include "expressiontype.h"
#include "log.h"

namespace peachy {

  class IntLiteralExpression : public Expression {

    public:

      IntLiteralExpression(Log * logger) : Expression(logger) {
        this->expressionType = EXPRESSION_INT_LITERAL;
        value = 0;
      }
      virtual ~IntLiteralExpression();
      void setValue(int value);
      int getValue();
      std::string toString();

    protected:

      int value;
  };
}

#endif
