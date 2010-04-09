#include "interpreter.h"

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
              case EXPRESSION_INT_LITERAL:
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
      case EXPRESSION_INT_LITERAL:
        logger->debug("Returning int literal object");
        IntLiteralExpression * ile =
          static_cast<IntLiteralExpression*>(expression);
        Int * i = new Int(logger, classFactory, ile->getValue());
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
