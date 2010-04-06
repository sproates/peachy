#include "scope.h"

#include "log.h"

namespace peachy {

  Scope::Scope(Log * logger) {
    logger->debug("Scope constructor");
    this->logger = logger;
  }

  Scope::~Scope() {
    logger->debug("Scope destructor");
  }
}
