#ifndef PEACHY_VARIABLEEXPRESSION_H
#define PEACHY_VARIABLEEXPRESSION_H

#include <string>

#include "expression.h"
#include "expressiontype.h"
#include "log.h"

namespace peachy {

  class VariableExpression : public Expression {

    public:

      VariableExpression(Log * logger) : Expression(logger) {
        logger->debug("VariableExpression constructor");
        this->expressionType = EXPRESSION_VARIABLE;
      }
      virtual ~VariableExpression();
      void setVariableName(std::string variableName);
      std::string getVariableName();

    protected:

      std::string variableName;
  };
}

#endif
