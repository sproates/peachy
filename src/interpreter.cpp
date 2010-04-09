#include "interpreter.h"

#include <iostream>

#include "additionexpression.h"
#include "assignmentexpression.h"
#include "class.h"
#include "classfactory.h"
#include "expression.h"
#include "expressionsource.h"
#include "expressiontype.h"
#include "interpreterexception.h"
#include "intliteralexpression.h"
#include "log.h"
#include "object.h"
#include "scope.h"
#include "stringliteralexpression.h"
#include "types/int.h"
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
    globalScope->addClass(stringClass);
    Class * intClass = classFactory->getClass(std::string("Int"));
    globalScope->addClass(intClass);
    Object * o;
    do {
      o = evaluate(expressionSource->nextExpression(), globalScope);
    } while(o != NULL);
    logger->debug(globalScope->toString());
    delete globalScope;
    logger->debug("Interpreter complete");
  }

  Object * Interpreter::evaluate(Expression * expression, Scope * scope) {
    logger->debug("Interpreter::evaluate()");
    Expression * lValue, * rValue;
    switch(expression->getExpressionType()) {
      case EXPRESSION_ADDITION:
        logger->debug("Addition expression found");
        AdditionExpression * addEx =
          static_cast<AdditionExpression*>(expression);
        lValue = addEx->getLValue();
        rValue = addEx->getRValue();
        switch(lValue->getExpressionType()) {
          case EXPRESSION_VARIABLE:
            logger->debug("Adding to a variable");
            VariableExpression * varEx =
              static_cast<VariableExpression*>(lValue);
            switch(rValue->getExpressionType()) {
              case EXPRESSION_INT_LITERAL:
              case EXPRESSION_VARIABLE:
                Object * o = evaluate(rValue, scope);
                if(scope->hasVariable(varEx->getVariableName())) {
                  logger->debug("Variable is already in scope");
                  if(scope->getVariable(varEx->getVariableName())->getClassName().compare(o->getClassName()) != 0) {
                    throw new InterpreterException("Can't assign a different type to this variable");
                  }
                  scope->replaceVariable(varEx->getVariableName(), o);
                } else {
                  logger->debug("Variable is not in scope");
                  scope->addVariable(varEx->getVariableName(), o);
                }
                return o;
              default:
                logger->debug("I don't know how to add one of those");
                throw InterpreterException("I don't know how to add one of those");
            }
            break;
          case EXPRESSION_INT_LITERAL:
            logger->debug("Adding to an int literal");
            IntLiteralExpression * intEx =
              static_cast<IntLiteralExpression*>(lValue);
            switch(rValue->getExpressionType()) {
              case EXPRESSION_INT_LITERAL:
                logger->debug("Adding int literals together");
                IntLiteralExpression * rIntEx =
                  static_cast<IntLiteralExpression*>(rValue);
                intEx->setValue(intEx->getValue() + rIntEx->getValue());
                return evaluate(intEx, scope);
              case EXPRESSION_VARIABLE:
                logger->debug("Adding a variable to an int");
                VariableExpression * varEx =
                  static_cast<VariableExpression*>(rValue);
                if(!scope->hasVariable(varEx->getVariableName())) {
                  logger->debug("Assigning an out of scope variable");
                  throw InterpreterException("Assigning a variable that isn't in scope");
                } else {
                  if(scope->getVariable(varEx->getVariableName())->getClassName().compare(std::string("Int")) != 0) {
                    logger->debug("Adding a non-int variable to an int literal...");
                    throw InterpreterException("Adding a non-int variable to an int literal");
                  } else {
                    logger->debug("Adding int variable to int literal");
                    Int * i = static_cast<Int*>(varEx->getValue());
                    intEx->setValue(intEx->getValue() + i->getValue());
                    return evaluate(intEx, scope);
                  }
                }
              default:
                logger->debug("I don't know how to add one of those");
                throw InterpreterException("I don't know how to add one of those");
            }
            break;
          default:
            logger->debug("Adding to what now?");
            throw InterpreterException("The target of an addition can only be an Int variable or an Int literal");
        }
        break;
      case EXPRESSION_ASSIGNMENT:
        logger->debug("Assignment expression found");
        AssignmentExpression * ae =
          static_cast<AssignmentExpression*>(expression);
        lValue = ae->getLValue();
        rValue = ae->getRValue();
        switch(lValue->getExpressionType()) {
          case EXPRESSION_VARIABLE:
            logger->debug("Assigning to a variable");
            VariableExpression * var =
              static_cast<VariableExpression*>(lValue);
            Object * o = evaluate(rValue, scope);
            var->setValue(o);
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
            return o;
          default:
            logger->debug("Assigning to what now?");
            throw InterpreterException("The target of an assignment should be a variable");
        }
        break;
      case EXPRESSION_INT_LITERAL:
        logger->debug("Returning int literal object");
        IntLiteralExpression * ile =
          static_cast<IntLiteralExpression*>(expression);
        Int * i = new Int(logger, classFactory, ile->getValue());
        std::cout << "Int literal with value: " << ile->getValue() << std::endl;
        return i;
      case EXPRESSION_QUIT:
        logger->debug("Quit expression found");
        return NULL;
      case EXPRESSION_STRING_LITERAL:
        logger->debug("Returning string literal object");
        StringLiteralExpression * e =
          static_cast<StringLiteralExpression*>(expression);
        String * o = new String(logger, classFactory, e->getStringValue());
        return o;
      case EXPRESSION_UNKNOWN:
      default:
        logger->debug("Unknown expression type");
        throw InterpreterException("I don't know what to do with that expression type");
    }
  }
}
