#include "interpreter.h"

#include <iostream>

#include "assignmentexpression.h"
#include "expression.h"
#include "expressionsource.h"
#include "expressiontype.h"
#include "interpreterexception.h"
#include "log.h"
#include "object.h"
#include "scope.h"
#include "stringliteralexpression.h"
#include "variableexpression.h"

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
    Scope * globalScope = new Scope(logger);
    Object * finalValue = evaluate(expressionSource->nextExpression(), globalScope);
    if(finalValue != NULL) {
      delete finalValue;
    }
    delete globalScope;
    logger->debug("Interpreter complete");
  }

  Object * Interpreter::evaluate(Expression * expression, Scope * scope) {
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
            VariableExpression * var =
              static_cast<VariableExpression*>(lValue);
            switch(rValue->getExpressionType()) {
              case EXPRESSION_STRING_LITERAL:
                logger->debug("It's a string literal, I know this");
                Object * o = evaluate(rValue, scope);
                if(scope->has(var->getVariableName())) {
                  logger->debug("Variable is already in scope");
                  scope->replace(var->getVariableName(), o);
                } else {
                  logger->debug("Variable not in scope");
                  scope->add(var->getVariableName(), o);
                }
                return o;
              case EXPRESSION_ASSIGNMENT:
                logger->debug("recursive assignment!");
                return evaluate(rValue, scope);
              default:
                logger->debug("I don't know how to assign one of those");
                throw InterpreterException("I don't know how to assign one of those");
            }
            break;
          default:
            logger->debug("Assigning to what now?");
            throw InterpreterException("Assigning to what now?");
        }
        break;
      case EXPRESSION_QUIT:
        logger->debug("Quit expression found");
        return NULL;
      case EXPRESSION_STRING_LITERAL:
        logger->debug("Returning string literal object");
        delete expression;
        return new Object(logger);
      case EXPRESSION_UNKNOWN:
      default:
        logger->debug("Unknown expression type");
        throw InterpreterException("I don't know what to do with that expression type");
    }
  }
}
