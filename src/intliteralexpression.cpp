#include "intliteralexpression.h"

namespace peachy {

  IntLiteralExpression::~IntLiteralExpression() {
    logger->debug("IntLiteralExpression destructor");
  }

  void IntLiteralExpression::setValue(int value) {
    logger->debug("IntLiteralExpression::setValue()");
    this->value = value;
  }

  int IntLiteralExpression::getValue() {
    logger->debug("IntLiteralExpression::getValue()");
    return value;
  }
}
