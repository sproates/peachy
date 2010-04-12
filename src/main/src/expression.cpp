#include "expression.h"

#include <string>

#include "expressiontype.h"
#include "log.h"

namespace peachy {

  Expression::Expression(Log * logger) {
    logger->debug("Expression constructor");
    this->logger = logger;
    this->expressionType = EXPRESSION_UNKNOWN;
    this->gotValue = false;
  }

  Expression::~Expression() {
    logger->debug("Expression destructor");
  }

  ExpressionType Expression::getExpressionType() {
    logger->debug("Expression::getExpressionType()");
    return expressionType;
  }

  std::string Expression::toString() {
    std::string s = std::string("Expression: \n");
    switch(expressionType) {
      case EXPRESSION_ASSIGNMENT:
        s.append("Assignment\n");
        break;
      case EXPRESSION_STRING_LITERAL:
        s.append("String literal\n");
        break;
      case EXPRESSION_QUIT:
        s.append("Quit");
        break;
      case EXPRESSION_UNKNOWN:
      default:
        s.append("Unknown type\n");
    }
    return s;
  }

  Expression::Expression(const Expression & e) {
    e.logger->debug("Expression copy constructor");
    logger = e.logger;
    expressionType = e.expressionType;
  }

  Expression & Expression::operator = (const Expression & e) {
    logger->debug("Expression assignment operator");
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