#include "booleanliteralexpression.h"

#include <string>

namespace peachy {

  BooleanLiteralExpression::~BooleanLiteralExpression() {}

  void BooleanLiteralExpression::setValue(bool value) {
    this->value = value;
  }

  bool BooleanLiteralExpression::getValue() {
    return value;
  }

  std::string BooleanLiteralExpression::toString() {
    if(value) {
      return std::string("true");
    } else {
      return std::string("false");
    }
  }
}
