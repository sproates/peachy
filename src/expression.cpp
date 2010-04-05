#include "expression.h"

#include <string>

#include "expressiontype.h"
#include "log.h"

namespace peachy {

  Expression::Expression(Log * logger) {
    logger->debug("Expression constructor");
    this->logger = logger;
    this->expressionType = EXPRESSION_UNKNOWN;
  }

  Expression::~Expression() {
    logger->debug("Expression destructor");
  }

  ExpressionType Expression::getExpressionType() {
    logger->debug("Expression::getExpressionType()");
    return expressionType;
  }

  void Expression::setLValue(std::string identifier) {
    logger->debug("Expression::setLValue()");
    lValue = identifier;
  }

  void Expression::setRValue(Expression * e) {
    logger->debug("Expression::setRValue()");
    rValue = e;
  }
}
