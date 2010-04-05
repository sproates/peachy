#include "variableexpression.h"

#include <string>

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
}
