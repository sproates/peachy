#include "variableexpression.h"

#include <stdexcept>
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

  void VariableExpression::setValue(Object * value) {
    logger->debug("VariableExpression::setValue()");
    if(this->gotValue) {
      logger->debug("Current value is set, must be a reassignment");
      if(!this->value->sameClass(value)) {
        throw std::runtime_error("Reassignment with different type");
      }
    } else {
      logger->debug("Current value not set, most be a new assignment");
    }
    this->value = value;
    gotValue = true;
  }
}
