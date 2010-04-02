#include "expressionfactory.h"

#include "expression.h"
#include "log.h"

namespace peachy {

  ExpressionFactory::ExpressionFactory(Log * logger, Log * expressionLogger) {
    logger->debug("ExpressionFactory constructor");
    this->logger = logger;
    this->expressionLogger = expressionLogger;
  }

  ExpressionFactory::~ExpressionFactory() {
    logger->debug("ExpressionFactory destructor");
  }

  Expression * ExpressionFactory::createExpression() {
    logger->debug("ExpressionFactory::createExpression()");
    return new Expression(expressionLogger);
  }

  Expression * ExpressionFactory::createExpression(Log * logger) {
    this->logger->debug("ExpressionFactory::createExpression()");
    return new Expression(logger);
  }
}
