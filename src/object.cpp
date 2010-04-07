#include "object.h"

#include <string>

#include "class.h"
#include "log.h"

namespace peachy {

  Object::Object(Log * logger, Class * clazz) {
    logger->debug("Object constructor");
    this->logger = logger;
    this->clazz = clazz;
  }

  Object::~Object() {
    logger->debug("Object destructor");
  }

  Class * Object::getClass() {
    return clazz;
  }

  std::string Object::getClassName() {
    return clazz->getName();
  }
}
