#include "environment.h"

#include "log.h"

namespace peachy {

  Environment::Environment(Log * logger) {
    this->logger = logger;
    logger->debug("Environment constructor");
  }

  Environment::~Environment() {
    logger->debug("Environment destructor");
  }
}

