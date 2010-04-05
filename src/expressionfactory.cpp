#include "expressionfactory.h"

#include "assignmentexpression.h"
#include "expression.h"
#include "log.h"
#include "quitexpression.h"
#include "stringliteralexpression.h"
#include "variableexpression.h"

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

  StringLiteralExpression * ExpressionFactory::createStringLiteralExpression() {
    logger->debug("ExpressionFactory::createStringLiteralExpression()");
    return new StringLiteralExpression(expressionLogger);
  }

  StringLiteralExpression * ExpressionFactory::createStringLiteralExpression(
    Log * logger) {
    this->logger->debug("ExpressionFactory::createStringLiteralExpression()");
    return new StringLiteralExpression(logger);
  }

  VariableExpression * ExpressionFactory::createVariableExpression() {
    logger->debug("ExpressionFactory::createVariableExpression()");
    return new VariableExpression(expressionLogger);
  }

  VariableExpression * ExpressionFactory::createVariableExpression(
    Log * logger) {
    this->logger->debug("ExpressionFactory::createVariableExpression()");
    return new VariableExpression(logger);
  }
}
