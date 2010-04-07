#include "function.h"

#include "log.h"

namespace peachy {

  Function::Function(Log * logger) {
    logger->debug("Function constructor");
    this->logger = logger;
  }

  Function::~Function() {
    logger->debug("Function destructor");
  }
}
