#include "object.h"

#include <stdexcept>
#include <string>

#include "class.h"
#include "classfactory.h"
#include "log.h"

namespace peachy {

  Object::Object(Log * logger, ClassFactory * classFactory) {
    this->logger = logger;
    this->classFactory = classFactory;
    this->clazz = classFactory->getClass(std::string("Unknown"));
  }

  Object::~Object() {}

  Class * Object::getClass() {
    return clazz;
  }

  std::string Object::getClassName() {
    if(clazz == NULL) {
      throw std::runtime_error("Class not initialised");
    }
    logger->debug(clazz->getName());
    return clazz->getName();
  }

  bool Object::is(std::string className) {
    return (clazz->getName().compare(className) == 0);
  }

  bool Object::is(Class * clazz) {
    return (this->clazz == clazz);
  }

  bool Object::sameClass(Object * o) {
    return (is(o->getClass()));
  }

  Object * Object::clone() {
    return this;
  }

  Object * Object::add(Object * o) {
    (void) o;
    throw std::runtime_error("Object does not support add()");
  }
}
