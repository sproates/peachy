#include "function.h"

#include <deque>
#include <string>

#include "expression.h"
#include "log.h"

namespace peachy {

  Function::Function(Log * logger, std::string name,
    std::deque<Expression*> expressions) {
    logger->debug("Function constructor");
    this->logger = logger;
    this->name = name;
    this->expressions = expressions;
  }

  Function::~Function() {
    logger->debug("Function destructor");
  }

  std::string Function::getName() {
    logger->debug("Function::getName()");
    return name;
  }

  std::deque<Expression*> Function::getExpressions() {
    logger->debug("Function::getExpressions()");
    return expressions;
  }
}
