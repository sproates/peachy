#include "scope.h"

#include <map>
#include <stdexcept>
#include <string>

#include "class.h"
#include "log.h"
#include "object.h"

namespace peachy {

  Scope::Scope(Log * logger) {
    logger->debug("Scope constructor");
    this->logger = logger;
  }

  Scope::~Scope() {
    logger->debug("Scope destructor");
  }

  bool Scope::hasVariable(const std::string name) {
    logger->debug("Scope::hasVariable()");
    return (variables.find(name) != variables.end());
  }

  bool Scope::hasClass(const std::string name) {
    logger->debug("Scope::hasClass()");
    return (classes.find(name) != classes.end());
  }

  Object * Scope::getVariable(const std::string name) {
    logger->debug("Scope::getVariable()");
    return variables.find(name)->second;
  }

  Class * Scope::getClass(const std::string name) {
    logger->debug("Scope::getClass()");
    if(hasClass(name)) {
      return classes[name];
    } else {
      throw std::runtime_error("Class not found");
    }
  }

  void Scope::addVariable(const std::string name, Object * value) {
    logger->debug("Scope::addVariable()");
    variables[name] = value;
  }

  void Scope::addClass(const std::string name, Class * clazz) {
    logger->debug("Scope::addClass()");
    classes[name] = clazz;
  }

  void Scope::replaceVariable(const std::string name, Object * value) {
    logger->debug("Scope::replace()");
    variables[name] = value;
  }

  std::string Scope::toString() {
    std::string s = std::string("Scope: \n");
    std::map<std::string, Object*>::iterator it;
    for(it = variables.begin(); it != variables.end(); it++) {
      s.append(it->first);
      s.append(" : ");
      s.append(it->second->getClassName());
      s.append("\n");
    }
    return s;
  }
}
