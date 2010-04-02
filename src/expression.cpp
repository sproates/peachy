#include "expression.h"

#include "log.h"

namespace peachy {

  Expression::Expression(Log * logger) {
    logger->debug("Expression constructor");
    this->logger = logger;
  }

  Expression::~Expression() {
    logger->debug("Expression destructor");
  }
}
