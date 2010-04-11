#include "assignmentexpression.h"

namespace peachy {

  AssignmentExpression::~AssignmentExpression() {
    logger->debug("AssignmentExpression destructor");
  }

  void AssignmentExpression::setLValue(Expression * e) {
    logger->debug("AssignmentExpression::setLValue()");
    lValue = e;
  }

  void AssignmentExpression::setRValue(Expression * e) {
    logger->debug("AssignmentExpression::setRValue()");
    rValue = e;
  }

  Expression * AssignmentExpression::getLValue() {
    logger->debug("AssignmentExpression::getLValue()");
    return lValue;
  }

  Expression * AssignmentExpression::getRValue() {
    logger->debug("AssignmentExpression::getRValue()");
    return rValue;
  }
}
