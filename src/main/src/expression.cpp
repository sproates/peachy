#include "expression.h"

#include <string>

#include "expressiontype.h"
#include "log.h"

namespace peachy {

  Expression::Expression(Log * logger) {
    this->logger = logger;
    this->expressionType = EXPRESSION_UNKNOWN;
    this->gotValue = false;
  }

  Expression::~Expression() {}

  ExpressionType Expression::getExpressionType() {
    return expressionType;
  }

  Expression::Expression(const Expression & e) {
    logger = e.logger;
    expressionType = e.expressionType;
  }

  Expression & Expression::operator = (const Expression & e) {
    if(this != &e) {
      logger = e.logger;
      expressionType = e.expressionType;
    }
    return *this;
  }

  bool Expression::hasValue() {
    return gotValue;
  }
}
