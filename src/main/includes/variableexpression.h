#ifndef PEACHY_VARIABLEEXPRESSION_H
#define PEACHY_VARIABLEEXPRESSION_H

#include <string>

#include "expression.h"
#include "expressiontype.h"
#include "log.h"

namespace peachy {

  class Object;

  class VariableExpression : public Expression {

    public:

      VariableExpression(Log * logger) : Expression(logger) {
        logger->debug("VariableExpression constructor");
        this->expressionType = EXPRESSION_VARIABLE;
      }
      virtual ~VariableExpression();
      void setVariableName(std::string variableName);
      std::string getVariableName();
      Object * getValue();
      void setValue(Object * value);

    protected:

      std::string variableName;
      Object * value;
  };
}

#endif
