#include "variableexpression.h"

#include <string>

#include "object.h"

namespace peachy {

  VariableExpression::~VariableExpression() {
    logger->debug("VariableExpression destructor");
  }

  void VariableExpression::setVariableName(std::string variableName) {
    logger->debug("VariableExpression::setVariableName()");
    this->variableName = variableName;
  }

  std::string VariableExpression::getVariableName() {
    logger->debug("VariableExpression::getVariableName()");
    return variableName;
  }

  Object * VariableExpression::getValue() {
    logger->debug("VariableExpression::getValue()");
    return value;
  }

  void VariableExpression::setValue(Object * value){
    this->value = value;
  }
}
