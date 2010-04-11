#include "stringliteralexpression.h"

#include <string>

namespace peachy {

  StringLiteralExpression::~StringLiteralExpression() {
    logger->debug("StringLiteralExpression destructor");
  }

  void StringLiteralExpression::setStringValue(std::string stringValue) {
    logger->debug("StringLiteralExpression::setStringValue()");
    this->stringValue = stringValue;
  }

  std::string StringLiteralExpression::getStringValue() {
    logger->debug("StringLiteralExpression::getStringValue()");
    return stringValue;
  }
}
