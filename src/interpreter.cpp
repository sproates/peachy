#include "interpreter.h"

#include <memory>

#include "expression.h"
#include "expressionsource.h"
#include "expressiontype.h"
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
      expression = expressionSource->nextExpression();
      switch(expression->getExpressionType()) {
        case EXPRESSION_ASSIGNMENT:
          logger->debug("Assignment expression found");
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
