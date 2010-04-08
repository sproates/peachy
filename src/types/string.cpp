#include "types/string.h"

#include <string>

#include "log.h"
#include "object.h"

namespace peachy {

  String::~String() {
    logger->debug("String destructor");
  }
}
