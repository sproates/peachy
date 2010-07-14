#include "booleanexpression.h"

#include "comparisontype.h"

#include <string>

namespace peachy {

  BooleanExpression::~BooleanExpression() {}

  void BooleanExpression::setLValue(Expression * e) {
    lValue = e;
  }

  void BooleanExpression::setRValue(Expression * e) {
    rValue = e;
  }

  ComparisonType BooleanExpression::getComparisonType() {
    return comparisonType;
  }

  void BooleanExpression::setComparisonType(ComparisonType c) {
    comparisonType = c;
  }

  Expression * BooleanExpression::getLValue() {
    return lValue;
  }

  Expression * BooleanExpression::getRValue() {
    return rValue;
  }

  std::string BooleanExpression::toString() {
    std::string s = std::string("Boolean expression [ ").append(lValue->toString());
    switch(comparisonType) {
      case(COMPARISON_NONE): {
        break;
      } case(COMPARISON_LESS_THAN): {
        s.append(" <");
        break;
      } default: {
        s.append(" Unknown comparison!");
        break;
      }
    }
    if(comparisonType != COMPARISON_NONE) {
      s.append(" ");
      s.append(rValue->toString());
    }
    s.append(" ]");
    return s;
  }
}
