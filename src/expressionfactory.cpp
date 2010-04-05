#include "expressionfactory.h"

#include "assignmentexpression.h"
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

  AssignmentExpression * ExpressionFactory::createAssignmentExpression() {
    logger->debug("ExpressionFactory::createAssignmentExpression()");
    return new AssignmentExpression(expressionLogger);
  }

  AssignmentExpression * ExpressionFactory::createAssignmentExpression(Log * logger) {
    this->logger->debug("ExpressionFactory::createAssignmentExpression()");
    return new AssignmentExpression(logger);
  }

  QuitExpression * ExpressionFactory::createQuitExpression() {
    logger->debug("ExpressionFactory::createQuitExpression()");
    return new QuitExpression(expressionLogger);
  }

  QuitExpression * ExpressionFactory::createQuitExpression(Log * logger) {
    this->logger->debug("ExpressionFactory::createQuitExpression()");
    return new QuitExpression(logger);
  }
}
