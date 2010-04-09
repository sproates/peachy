#include "types/string.h"

#include <ostream>
#include <string>

#include "log.h"
#include "object.h"

namespace peachy {

  String::~String() {
    logger->debug("String destructor");
  }

  std::string String::getValue() {
    return value;
  }
}
