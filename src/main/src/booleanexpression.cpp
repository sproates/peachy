#include "booleanexpression.h"

#include <string>

namespace peachy {

  BooleanExpression::~BooleanExpression() {}

  void BooleanExpression::setLValue(Expression * e) {
    lValue = e;
  }

  void BooleanExpression::setRValue(Expression * e) {
    rValue = e;
  }

  Expression * BooleanExpression::getLValue() {
    return lValue;
  }

  Expression * BooleanExpression::getRValue() {
    return rValue;
  }

  std::string BooleanExpression::toString() {
    return std::string("");
  }
}
