#include "stringliteralexpression.h"

#include <string>

namespace peachy {

  StringLiteralExpression::~StringLiteralExpression() {}

  void StringLiteralExpression::setStringValue(std::string stringValue) {
    this->stringValue = stringValue;
  }

  std::string StringLiteralExpression::getStringValue() {
    return stringValue;
  }

  std::string StringLiteralExpression::toString() {
    std::string s = std::string("\"");
    s.append(stringValue);
    s.append("\"");
    return s;
  }
}
