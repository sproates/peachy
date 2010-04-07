#include "class.h"

#include <string>

#include "log.h"

namespace peachy {

  Class::Class(Log * logger, std::string name) {
    logger->debug("Class constructor");
    this->logger = logger;
    this->name = name;
  }

  Class::~Class() {
    logger->debug("Class destructor");
  }
}
