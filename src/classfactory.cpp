#include "classfactory.h"

#include <map>
#include <stdexcept>
#include <string>

#include "class.h"
#include "log.h"

namespace peachy {

  ClassFactory::ClassFactory(Log * logger, Log * classLogger) {
    logger->debug("ClassFactory constructor");
    this->logger = logger;
    this->classLogger = classLogger;
  }

  ClassFactory::~ClassFactory() {
    logger->debug("ClassFactory destructor");
  }

  Class * ClassFactory::getClass(std::string name) {
    logger->debug("ClassFactory::getClass()");
    if(classes.find(name) == classes.end()) {
      classes[name] = new Class(classLogger, name);
    }
    return classes[name];
  }
}
