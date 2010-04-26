#include "interpreter.h"

#include <list>
#include <iostream>

#include "additionexpression.h"
#include "assignmentexpression.h"
#include "class.h"
#include "classfactory.h"
#include "expression.h"
#include "expressionsource.h"
#include "expressiontype.h"
#include "function.h"
#include "functions/print.h"
#include "interpreterexception.h"
#include "intliteralexpression.h"
#include "log.h"
#include "nativefunction.h"
#include "object.h"
#include "scope.h"
#include "stringliteralexpression.h"
#include "types/int.h"
#include "types/string.h"
#include "valueexpression.h"
#include "variableexpression.h"

namespace peachy {
  
  Interpreter::Interpreter(Log * logger, ExpressionSource * expressionSource,
    ClassFactory * classFactory) {
    this->logger = logger;
    this->expressionSource = expressionSource;
    this->classFactory = classFactory;
  }

  Interpreter::~Interpreter() {}

  void Interpreter::run() {
    Scope * globalScope = new Scope(logger);
    Class * stringClass = classFactory->getClass(std::string("String"));
    globalScope->addClass(stringClass);
    Class * intClass = classFactory->getClass(std::string("Int"));
    globalScope->addClass(intClass);
    globalScope->addNativeFunction(std::string("print"), new Print());
    Expression * e;
    do {
      e = evaluate(expressionSource->nextExpression(), globalScope);
    } while(e != NULL);
  }

  Expression * Interpreter::evaluate(Expression * expression, Scope * scope) {
    Expression * lValue, * rValue;
    switch(expression->getExpressionType()) {
      case EXPRESSION_ADDITION:
        AdditionExpression * addEx =
          static_cast<AdditionExpression*>(expression);
        if(addEx == NULL) {
          throw InterpreterException("Invalid expression");
        }
        lValue = addEx->getLValue();
        rValue = addEx->getRValue();
        switch(lValue->getExpressionType()) {
          case EXPRESSION_VARIABLE:
            VariableExpression * varEx =
              static_cast<VariableExpression*>(lValue);
            if(!scope->hasVariable(varEx->getVariableName())) {
              throw InterpreterException("variable is not in this scope");
            }
            Object * leftObj = scope->getVariable(varEx->getVariableName());
            Expression * rightEx = evaluate(rValue, scope);
            switch(rightEx->getExpressionType()) {
              case EXPRESSION_VALUE:
                ValueExpression * valEx =
                  static_cast<ValueExpression*>(rightEx);
                if(valEx == NULL) {
                  throw InterpreterException("Invalid expression");
                }
                Object * rightObj = valEx->getValue();
                Object * newValue;
                if(leftObj->getClassName().compare("Int") == 0) {
                  Int * leftObjInt = static_cast<Int*>(leftObj);
                  newValue = leftObjInt->add(rightObj);   
                } else if(leftObj->getClassName().compare("String") == 0) {
                  String * leftObjString = static_cast<String*>(leftObj);
                  newValue = leftObjString->add(rightObj);
                } else {
                  throw InterpreterException("Unsupported operation");
                }
                valEx->setValue(newValue);
                return valEx;
              default:
                throw InterpreterException("Invalid expression");
            }
          case EXPRESSION_INT_LITERAL:
            IntLiteralExpression * intEx =
              static_cast<IntLiteralExpression*>(lValue);
            switch(rValue->getExpressionType()) {
              case EXPRESSION_INT_LITERAL:
                IntLiteralExpression * rIntEx =
                  static_cast<IntLiteralExpression*>(rValue);
                intEx->setValue(intEx->getValue() + rIntEx->getValue());
                return evaluate(intEx, scope);
              case EXPRESSION_VARIABLE:
                VariableExpression * varEx =
                  static_cast<VariableExpression*>(rValue);
                if(!scope->hasVariable(varEx->getVariableName())) {
                  throw InterpreterException("Assigning a variable that isn't in scope");
                } else {
                  if(scope->getVariable(varEx->getVariableName())->getClassName().compare(std::string("Int")) != 0) {
                    throw InterpreterException("Adding a non-int variable to an int literal");
                  } else {
                    Int * i = static_cast<Int*>(varEx->getValue());
                    intEx->setValue(intEx->getValue() + i->getValue());
                    return evaluate(intEx, scope);
                  }
                }
              default:
                throw InterpreterException("I don't know how to add one of those to an int literal");
            }
            break;
          case EXPRESSION_STRING_LITERAL:
            StringLiteralExpression * stringEx =
              static_cast<StringLiteralExpression*>(lValue);
            switch(rValue->getExpressionType()) {
              case EXPRESSION_STRING_LITERAL:
                StringLiteralExpression * rStringEx =
                  static_cast<StringLiteralExpression*>(rValue);
                stringEx->setStringValue(stringEx->getStringValue().append(rStringEx->getStringValue()));
                return evaluate(stringEx, scope);
              case EXPRESSION_VARIABLE:
                VariableExpression * varEx =
                  static_cast<VariableExpression*>(rValue);
                if(!scope->hasVariable(varEx->getVariableName())) {
                  throw InterpreterException(varEx->getVariableName().append(" is not defined"));
                } else {
                  if(scope->getVariable(varEx->getVariableName())->getClassName().compare(std::string("String")) != 0) {
                    throw InterpreterException("Adding a non-string variable to a string literal");
                  } else {
                    String * s = static_cast<String*>(varEx->getValue());
                    stringEx->setStringValue(stringEx->getStringValue().append(s->getValue()));
                    return evaluate(stringEx, scope);
                  }
                }
              default:
                throw InterpreterException("I don't know how to add one of those to a string literal");
            }
            break;
          default:
            throw InterpreterException("The target of an addition can only be an Int variable or an Int literal");
        }
        break;
      case EXPRESSION_ASSIGNMENT:
        AssignmentExpression * ae =
          static_cast<AssignmentExpression*>(expression);
        lValue = ae->getLValue();
        rValue = ae->getRValue();
        switch(lValue->getExpressionType()) {
          case EXPRESSION_VALUE:
            throw InterpreterException("lvalue of assignment is a value");
          case EXPRESSION_VARIABLE:
            logger->debug("lvalue of assignment is a variable");
            VariableExpression * var =
              static_cast<VariableExpression*>(lValue);
            if(var == NULL) {
              throw InterpreterException("Invalid lValue");
            }
            Expression * rVal = evaluate(rValue, scope);
            switch(rVal->getExpressionType()) {
              case EXPRESSION_VALUE:
                logger->debug("rvalue is a value");
                ValueExpression * rValue =
                  static_cast<ValueExpression*>(rVal);
                Object * rObj = rValue->getValue();
                if(scope->hasNativeFunction(var->getVariableName())) {
                  logger->debug("this is a function call");
                  NativeFunction * f =
                    scope->getNativeFunction(var->getVariableName());
                  logger->debug("got function from scope");
                  logger->debug(rValue->toString());
                  std::list<Object*> params;
                  params.push_front(rValue->getValue());
                  logger->debug("calling function");
                  Object * result = f->call(params);
                  logger->debug("Returning result of function call:");
                  logger->debug(result->toString());
                  return new ValueExpression(logger, result);
                } else {
                  logger->debug("straightforward assignment");
                  var->setValue(rObj);
                }
                return var;
              case EXPRESSION_VARIABLE:
                logger->debug("rvalue is a variable");
                VariableExpression * rVar =
                  static_cast<VariableExpression*>(rVal);
                if(rVar == NULL) {
                  throw InterpreterException("Invalid variable");
                }
                if(scope->hasNativeFunction(var->getVariableName())) {
                  logger->debug("rvalue is a native function");
                  NativeFunction * f =
                    scope->getNativeFunction(var->getVariableName());
                  logger->debug("got function from scope");
                  logger->debug(rVal->toString());
                  std::list<Object*> params;
                  params.push_front(rVar->getValue());
                  logger->debug("calling function");
                  Object * result = f->call(params);
                  logger->debug("Returning result of function call:");
                  logger->debug(result->toString());
                  return new ValueExpression(logger, result);
                } else {
                  logger->debug("rvalue is a variable");
                  Object * rObj = rValue->getValue();
                  var->setValue(rObj);
                  return var;
                }
                break;
              default:
                throw InterpreterException("Unexpected rvalue");
            }
          case EXPRESSION_ASSIGNMENT:
            logger->debug("lvalue of assignment is assignment");
            ValueExpression * lVal =
              static_cast<ValueExpression*>(evaluate(lValue, scope));
            if(lVal == NULL) {
              throw InterpreterException("Invalid expression");
            }
            ValueExpression * rValue =
              static_cast<ValueExpression*>(evaluate(rValue, scope));
            if(rVal == NULL) {
              throw InterpreterException("Invalid expression");
            }
            lVal->setValue(rValue->getValue());
            return lVal;
          default:
            logger->debug("something else");
            throw InterpreterException("Invalid assignment");
        }
        break;
      case EXPRESSION_INT_LITERAL:
        IntLiteralExpression * ile =
          static_cast<IntLiteralExpression*>(expression);
        return new ValueExpression(logger, 
          new Int(logger, classFactory, ile->getValue()));
      case EXPRESSION_QUIT:
        return NULL;
      case EXPRESSION_STRING_LITERAL:
        StringLiteralExpression * e =
          static_cast<StringLiteralExpression*>(expression);
        return new ValueExpression(logger,
          new String(logger, classFactory, e->getStringValue()));
      case EXPRESSION_VARIABLE:
        VariableExpression * varEx =
          static_cast<VariableExpression*>(expression);
        if(!scope->hasVariable(varEx->getVariableName())) {
          scope->addVariable(varEx->getVariableName(), varEx->getValue());
        }
        Object * varObj = scope->getVariable(varEx->getVariableName());
        varEx->setValue(varObj);
        logger->debug("returning variable:");
        logger->debug(varEx->toString());
        return varEx;
      case EXPRESSION_VALUE:
        logger->debug("returning value:");
        logger->debug(expression->toString());
        return expression;
      case EXPRESSION_UNKNOWN:
      default:
        throw InterpreterException("Unknown expression");
    }
  }

  void Interpreter::dumpVar(VariableExpression * v) {
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
