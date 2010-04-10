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
            if(!scope->hasVariable(varEx->getVariableName())) {
              throw InterpreterException("variable is not in this scope");
            }
            Object * leftObj = scope->getVariable(varEx->getVariableName());
            logger->debug("Evaluating RHS of addition");
            Object * rightObj = evaluate(rValue, scope);
            leftObj->add(rightObj);
            return leftObj;
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
                logger->debug("I don't know how to add one of those to an int literal");
                throw InterpreterException("I don't know how to add one of those to an int literal");
            }
            break;
          case EXPRESSION_STRING_LITERAL:
            logger->debug("Adding to a String literal");
            StringLiteralExpression * stringEx =
              static_cast<StringLiteralExpression*>(lValue);
            switch(rValue->getExpressionType()) {
              case EXPRESSION_STRING_LITERAL:
                logger->debug("Adding String literals together");
                StringLiteralExpression * rStringEx =
                  static_cast<StringLiteralExpression*>(rValue);
                stringEx->setStringValue(stringEx->getStringValue().append(rStringEx->getStringValue()));
                return evaluate(stringEx, scope);
              case EXPRESSION_VARIABLE:
                logger->debug("Adding a variable to a String");
                VariableExpression * varEx =
                  static_cast<VariableExpression*>(rValue);
                if(!scope->hasVariable(varEx->getVariableName())) {
                  logger->debug("Assigning an out of scope variable");
                  throw InterpreterException("Assigning a variable that isn't in scope");
                } else {
                  if(scope->getVariable(varEx->getVariableName())->getClassName().compare(std::string("String")) != 0) {
                    logger->debug("Adding a non-string variable to a string literal...");
                    throw InterpreterException("Adding a non-string variable to a string literal");
                  } else {
                    logger->debug("Adding string variable to string literal");
                    String * s = static_cast<String*>(varEx->getValue());
                    stringEx->setStringValue(stringEx->getStringValue().append(s->getValue()));
                    return evaluate(stringEx, scope);
                  }
                }
              default:
                logger->debug("I don't know how to add one of those to a string literal");
                throw InterpreterException("I don't know how to add one of those to a string literal");
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
            if(var == NULL) {
              logger->debug("lValue of assignment had type EXPRESSION_VARIABLE but did not cast to VariableExpression");
              throw InterpreterException("lValue of assignment had type EXPRESSION_VARIABLE but did not cast to VariableExpression");
            }
            logger->debug("Evaluating RHS of assignment");
            Object * rightObj = evaluate(rValue, scope);
            logger->debug("RHS of assignment evaluated");
            var->setValue(rightObj);
            logger->debug("flag 2");
            dumpVar(var);
            if(scope->hasVariable(var->getVariableName())) {
              logger->debug("Variable is already in scope");
              scope->replaceVariable(var->getVariableName(), rightObj);
            } else {
              logger->debug("Variable not yet in scope");
              scope->addVariable(var->getVariableName(), rightObj);
            }
            logger->debug("Dumping the variable I just assigned to...");
            dumpVar(var);
            return rightObj;
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
        std::cout << i->getClassName() << std::endl;
        return i;
      case EXPRESSION_QUIT:
        logger->debug("Quit expression found");
        return NULL;
      case EXPRESSION_STRING_LITERAL:
        logger->debug("Returning string literal object");
        StringLiteralExpression * e =
          static_cast<StringLiteralExpression*>(expression);
        return new String(logger, classFactory, e->getStringValue());
      case EXPRESSION_UNKNOWN:
      default:
        logger->debug("Unknown expression type");
        throw InterpreterException("I don't know what to do with that expression type");
    }
  }

  void Interpreter::dumpVar(VariableExpression * v) {
    logger->debug("Interpreter::dumpVar()");
    if(v->hasValue()) {
      std::string className = v->getValue()->getClassName();
      std::cout << v->getVariableName();
      dumpObj(v->getValue());
    } else {
      std::cout << " (no value)" << std::endl;
    }
  }

  void Interpreter::dumpObj(Object * o) {
    std::string className = o->getClassName();
    if(className.compare("Int") == 0 ) {
      Int * i = static_cast<Int*>(o);
      std::cout << " [Int] " << i->getValue() << std::endl;
    } else if(className.compare("String") == 0) {
      String * s = static_cast<String*>(o);
      std::cout << " [String] " << s->getValue() << std::endl;
    } else if(className.compare("Object") == 0) {
      std::cout << " [Object]" << std::endl;
    } else {
      std::cout << "[Unknown type]" << std::endl;
    }
  }
}
