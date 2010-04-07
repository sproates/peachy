#include "class.h"

#include "log.h"

namespace peachy {

  Class::Class(Log * logger) {
    logger->debug("Class constructor");
    this->logger = logger;
  }

  Class::~Class() {
    logger->debug("Class destructor");
  }
}
