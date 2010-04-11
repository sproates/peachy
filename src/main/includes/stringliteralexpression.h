#ifndef PEACHY_STRINGLITERALEXPRESSION_H
#define PEACHY_STRINGLITERALEXPRESSION_H

#include <string>

#include "expression.h"
#include "expressiontype.h"
#include "log.h"

namespace peachy {

  class StringLiteralExpression : public Expression {

    public:

      StringLiteralExpression(Log * logger) : Expression(logger) {
        logger->debug("StringLiteralExpression constructor");
        this->expressionType = EXPRESSION_STRING_LITERAL;
      }
      virtual ~StringLiteralExpression();
      void setStringValue(std::string stringValue);
      std::string getStringValue();

    protected:

      std::string stringValue;
  };
}

#endif
