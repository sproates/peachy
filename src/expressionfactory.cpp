#include "expressionfactory.h"

#include "expression.h"
#include "log.h"
#include "quitexpression.h"

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

  Expression * ExpressionFactory::createQuitExpression() {
    logger->debug("ExpressionFactory::createQuitExpression()");
    return new QuitExpression(expressionLogger);
  }

  Expression * ExpressionFactory::createQuitExpression(Log * logger) {
    this->logger->debug("ExpressionFactory::createQuitExpression()");
    return new QuitExpression(logger);
  }
}
