#include "types/string.h"

#include <string>

#include "log.h"

namespace peachy {

  String::String(Log * logger, std::string value) {
    logger->debug("String constructor");
    this->logger = logger;
    this->value = value;
  }

  String::~String() {
    logger->debug("String destructor");
  }
}
