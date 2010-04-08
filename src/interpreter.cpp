#include "interpreter.h"

#include <iostream>
#include <typeinfo>

#include "assignmentexpression.h"
#include "class.h"
#include "classfactory.h"
#include "expression.h"
#include "expressionsource.h"
#include "expressiontype.h"
#include "interpreterexception.h"
#include "log.h"
#include "object.h"
#include "scope.h"
#include "stringliteralexpression.h"
#include "types/string.h"
#include "variableexpression.h"

namespace peachy {
  
  Interpreter::Interpreter(Log * logger, ExpressionSource * expressionSource,
    ClassFactory * classFactory) {
    logger->debug("Interpreter constructor");
    this->logger = logger;
    this->expressionSource = expressionSource;
    this->classFactory = classFactory;
  }

  Interpreter::~Interpreter() {
    logger->debug("Interpreter destructor");
  }

  void Interpreter::run() {
    logger->debug("Interpreter::run()");
    Scope * globalScope = new Scope(logger);
    Class * stringClass = classFactory->getClass(std::string("String"));
    globalScope->addClass(std::string("String"), stringClass);
    Object * o = evaluate(expressionSource->nextExpression(), globalScope);
    std::cout << "Final object of type: " << typeid(o).name() << std::endl;
    logger->debug(globalScope->toString());
    delete stringClass;
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
              case EXPRESSION_ASSIGNMENT:
                Object * o = evaluate(rValue, scope);
                if(scope->hasVariable(var->getVariableName())) {
                  logger->debug("Variable is already in scope");
                  if(scope->getVariable(var->getVariableName())->getClassName() != o->getClassName()) {
                    throw new InterpreterException("Can't assign a different type to this variable");
                  }
                  scope->replaceVariable(var->getVariableName(), o);
                } else {
                  logger->debug("Variable not in scope");
                  scope->addVariable(var->getVariableName(), o);
                }
                std::cout << "Returning object of type: " << typeid(o).name() << std::endl;
                return o;
              default:
                logger->debug("I don't know how to assign one of those");
                throw InterpreterException("I don't know how to assign one of those");
            }
            break;
          default:
            logger->debug("Assigning to what now?");
            throw InterpreterException("The target of an assignment should be a variable");
        }
        break;
      case EXPRESSION_QUIT:
        logger->debug("Quit expression found");
        return NULL;
      case EXPRESSION_STRING_LITERAL:
        logger->debug("Returning string literal object");
        StringLiteralExpression * e =
          static_cast<StringLiteralExpression*>(expression);
        String * o = new String(logger, classFactory, e->getStringValue());
        std::cout << "Returning object of type: " << typeid(o).name() << std::endl;
        return o;
      case EXPRESSION_UNKNOWN:
      default:
        logger->debug("Unknown expression type");
        throw InterpreterException("I don't know what to do with that expression type");
    }
  }
}
