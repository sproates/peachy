#include "additionexpression.h"

#include <string>

namespace peachy {

  AdditionExpression::~AdditionExpression() {}

  void AdditionExpression::setLValue(Expression * e) {
    lValue = e;
  }

  void AdditionExpression::setRValue(Expression * e) {
    rValue = e;
  }

  Expression * AdditionExpression::getLValue() {
    return lValue;
  }

  Expression * AdditionExpression::getRValue() {
    return rValue;
  }

  std::string AdditionExpression::toString() {
    std::string s = "";
    if(lValue != NULL) {
      s.append(lValue->toString());
    } else {
      s.append("[undefined]");
    }
    s.append(" + ");
    if(rValue != NULL) {
      s.append(rValue->toString());
    } else {
      s.append("[undefined]");
    }
    return s;
  }
}
