#ifndef PEACHY_BOOLEANLITERALEXPRESSION_H
#define PEACHY_BOOLEANLITERALEXPRESSION_H

#include <string>

#include "expression.h"
#include "expressiontype.h"
#include "log.h"

namespace peachy {

  class BooleanLiteralExpression : public Expression {

    public:

      BooleanLiteralExpression(Log * logger) : Expression(logger) {
        this->expressionType = EXPRESSION_BOOLEAN_LITERAL;
        this->value = false;
      }

      BooleanLiteralExpression(Log * logger, bool value) : Expression(logger) {
        this->expressionType = EXPRESSION_BOOLEAN_LITERAL;
        this->value = value;
      }
      virtual ~BooleanLiteralExpression();
      void setValue(bool value);
      bool getValue();
      std::string toString();

    protected:

      bool value;
  };
}

#endif
