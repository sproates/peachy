#include "additionexpression.h"

namespace peachy {

  AdditionExpression::~AdditionExpression() {
    logger->debug("AdditionExpression destructor");
  }

  void AdditionExpression::setLValue(Expression * e) {
    logger->debug("AdditionExpression::setLValue()");
    lValue = e;
  }

  void AdditionExpression::setRValue(Expression * e) {
    logger->debug("AdditionExpression::setRValue()");
    rValue = e;
  }

  Expression * AdditionExpression::getLValue() {
    logger->debug("AdditionExpression::getLValue()");
    return lValue;
  }

  Expression * AdditionExpression::getRValue() {
    logger->debug("AdditionExpression::getRValue()");
    return rValue;
  }
}
