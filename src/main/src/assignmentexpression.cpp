#include "assignmentexpression.h"

#include <string>

namespace peachy {

  AssignmentExpression::~AssignmentExpression() {}

  void AssignmentExpression::setLValue(Expression * e) {
    lValue = e;
  }

  void AssignmentExpression::setRValue(Expression * e) {
    rValue = e;
  }

  Expression * AssignmentExpression::getLValue() {
    return lValue;
  }

  Expression * AssignmentExpression::getRValue() {
    return rValue;
  }

  std::string AssignmentExpression::toString() {
    std::string s = "";
    if(lValue != NULL) {
      s.append(lValue->toString());
    } else {
      s.append("[undefined]");
    }
    s.append(" <- ");
    if(rValue != NULL) {
      s.append(rValue->toString());
    } else {
      s.append("[undefined]");
    }
    return s;
  }
}
