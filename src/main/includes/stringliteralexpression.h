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
        this->expressionType = EXPRESSION_STRING_LITERAL;
        stringValue = std::string("");
      }
      virtual ~StringLiteralExpression();
      void setStringValue(std::string stringValue);
      std::string getStringValue();
      std::string toString();

    protected:

      std::string stringValue;
  };
}

#endif
