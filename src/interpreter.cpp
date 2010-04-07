#include "interpreter.h"

#include <iostream>

#include "assignmentexpression.h"
#include "expression.h"
#include "expressionsource.h"
#include "expressiontype.h"
#include "interpreterexception.h"
#include "log.h"
#include "stringliteralexpression.h"

namespace peachy {
  
  Interpreter::Interpreter(Log * logger, ExpressionSource * expressionSource) {
    logger->debug("Interpreter constructor");
    this->logger = logger;
    this->expressionSource = expressionSource;
  }

  Interpreter::~Interpreter() {
    logger->debug("Interpreter destructor");
  }

  void Interpreter::run() {
    logger->debug("Interpreter::run()");
    evaluate(expressionSource->nextExpression());
    logger->debug("Interpreter complete");
  }

  void Interpreter::evaluate(Expression * expression) {
    logger->debug("Interpreter::evaluate()");
    switch(expression->getExpressionType()) {
      case EXPRESSION_ASSIGNMENT:
        logger->debug("Assignment expression found");
        AssignmentExpression * ae =
          static_cast<AssignmentExpression*>(expression);
        Expression * lValue = ae->getLValue();
        Expression * rValue = ae->getRValue();
        switch(lValue->getExpressionType()) {
          case EXPRESSION_VARIABLE:
            logger->debug("Assigning to a variable");
            switch(rValue->getExpressionType()) {
              case EXPRESSION_STRING_LITERAL:
                logger->debug("It's a string literal, I know this");
                StringLiteralExpression * e =
                  static_cast<StringLiteralExpression*>(rValue);
                logger->debug(e->getStringValue());
                break;
              case EXPRESSION_ASSIGNMENT:
                logger->debug("recursive assignment!");
                throw InterpreterException("I don't do recurisve assignment yet :(");
              default:
                logger->debug("I don't know how to assign one of those");
                throw InterpreterException("I don't know how to assign one of those");
            }
            break;
          default:
            logger->debug("Assigning to what now?");
            throw InterpreterException("Assigning to what now?");
        }
        delete lValue;
        delete rValue;
        break;
      case EXPRESSION_QUIT:
        logger->debug("Quit expression found");
        return;
      case EXPRESSION_STRING_LITERAL:
      case EXPRESSION_UNKNOWN:
      default:
        throw InterpreterException("I don't know what to do with that expression type");
    }
  }
}
