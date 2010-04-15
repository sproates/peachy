#include "class.h"

#include <string>

#include "log.h"

namespace peachy {

  Class::Class(Log * logger, std::string name) {
    this->logger = logger;
    this->name = name;
  }

  Class::~Class() {}

  std::string Class::getName() {
    return name;
  }
}
