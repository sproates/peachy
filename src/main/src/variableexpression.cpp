#include "variableexpression.h"

#include <stdexcept>
#include <string>

#include "object.h"

namespace peachy {

  VariableExpression::~VariableExpression() {}

  void VariableExpression::setVariableName(std::string variableName) {
    this->variableName = variableName;
  }

  std::string VariableExpression::getVariableName() {
    return variableName;
  }

  Object * VariableExpression::getValue() {
    return value;
  }

  void VariableExpression::setValue(Object * value) {
    if(this->gotValue) {
      if(!this->value->sameClass(value)) {
        throw std::runtime_error("Reassignment with different type");
      }
    }
    this->value = value;
    gotValue = true;
  }

  std::string VariableExpression::toString() {
    if(variableName.size() > 0) {
      return variableName;
    } else {
      return std::string("[undefined]");
    }
  }
}
