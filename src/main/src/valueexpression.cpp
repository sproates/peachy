#include "valueexpression.h"

#include <string>

#include "object.h"

namespace peachy {

  ValueExpression::~ValueExpression() {}

  Object * ValueExpression::getValue() {
    return value;
  }

  void ValueExpression::setValue(Object * value) {
    this->value = value;
    gotValue = true;
  }

  std::string ValueExpression::toString() {
    if(gotValue) {
      return std::string("Value: ").append(value->getClassName());
    } else {
      return std::string("Value: empty");
    }
  }
}
