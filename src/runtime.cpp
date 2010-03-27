#include "runtime.h"

#include "log.h"

namespace peachy {

  Runtime::Runtime(Log * logger) {
    this->logger = logger;
    logger->debug("Runtime constructor");
  }

  Runtime::~Runtime() {
    logger->debug("Runtime destructor");
  }
}
