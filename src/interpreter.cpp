#include "interpreter.h"

#include <memory>

#include "expression.h"
#include "expressionsource.h"
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
    std::auto_ptr<Expression> expression = expressionSource->nextExpression();
    logger->debug("Interpreter complete");
  }
}
