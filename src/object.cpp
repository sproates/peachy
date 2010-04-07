#include "object.h"

#include "class.h"
#include "log.h"

namespace peachy {

  Object::Object(Log * logger) {
    logger->debug("Object constructor");
    this->logger = logger;
  }

  Object::~Object() {
    logger->debug("Object destructor");
  }

  Class * Object::getClass() {
    return clazz;
  }
}
