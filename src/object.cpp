#include "object.h"

#include <string>

#include "class.h"
#include "classfactory.h"
#include "log.h"

namespace peachy {

  Object::Object(Log * logger, ClassFactory * classFactory) {
    logger->debug("Object constructor");
    this->logger = logger;
    this->classFactory = classFactory;
    this->clazz = classFactory->getClass(std::string("Unknown"));
  }

  Object::~Object() {
    logger->debug("Object destructor");
  }

  Class * Object::getClass() {
    logger->debug("Object::getClass()");
    return clazz;
  }

  std::string Object::getClassName() {
    logger->debug("Object::getClassName()");
    return clazz->getName();
  }
}
