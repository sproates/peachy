#include "interpreter.h"

#include <memory>

#include "expression.h"
#include "expressionsource.h"
#include "expressiontype.h"
#include "interpreterexception.h"
#include "log.h"

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
    std::auto_ptr<Expression> expression;
    bool quitting = false;
    while(!quitting) {
      logger->debug("Getting next expression");
      expression = expressionSource->nextExpression();
      switch(expression->getExpressionType()) {
        case EXPRESSION_ASSIGNMENT:
          logger->debug("Assignment expression found");
          Expression * lValue = expression.get()->getLValue();
          Expression * rValue = expression.get()->getRValue();
          switch(lValue->getExpressionType()) {
            case EXPRESSION_VARIABLE:
              logger->debug("Assigning to a variable");
              switch(rValue->getExpressionType()) {
                case EXPRESSION_STRING_LITERAL:
                  logger->debug("It's a string literal, I know this");
                  break;
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
          quitting = true;
          break;
        case EXPRESSION_STRING_LITERAL:
        case EXPRESSION_UNKNOWN:
        default:
          logger->debug("I don't know what to do with that expression type");
          return;
      }
    }
    logger->debug("Interpreter complete");
  }
}
