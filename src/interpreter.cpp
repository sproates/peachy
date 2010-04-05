#include "interpreter.h"

#include "log.h"

namespace peachy {

  
  Interpreter::Interpreter(Log * logger) {
    logger->debug("Interpreter constructor");
    this->logger = logger;
  }

  Interpreter::~Interpreter() {
    logger->debug("Interpreter destructor");
  }
}
