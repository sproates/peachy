
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
    std::map<std::string, Object*>::iterator it;
    logger->debug("Deleting objects...");
    for(it = variables.begin(); it != variables.end(); it++) {
      logger->debug(
        std::string("Deleting object: ").
        append(it->first)
      );
      variables.erase(it);
    }
    logger->debug("Scope destruction complete");
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

  void Scope::addClass(Class * clazz) {
    logger->debug("Scope::addClass()");
    if(hasClass(clazz->getName())) {
      throw std::runtime_error("Class already defined in this scope");
    }
    classes[clazz->getName()] = clazz;
  }

  void Scope::replaceVariable(const std::string name, Object * value) {
    logger->debug("Scope::replace()");
    if(hasVariable(name)) {
      if(variables[name]->getClassName().compare(value->getClassName()) != 0) {
        throw std::runtime_error(
          std::string("").
          append(name).
          append(std::string(" already defined with class ")).
          append(variables[name]->getClassName()).
          append(std::string(" in this scope"))
        );
      }
    }
    variables[name] = value;
  }

  std::string Scope::toString() {
    std::string s = std::string("Scope: \n");
    s.append("Objects:\n");
    std::map<std::string, Object*>::iterator it;
    for(it = variables.begin(); it != variables.end(); it++) {
      s.append(it->first);
      s.append(" : ");
      s.append(it->second->getClassName());
      s.append("\n");
    }
    s.append("Classes\n");
    std::map<std::string, Class*>::iterator it2;
    for(it2 = classes.begin(); it2 != classes.end(); it2++) {
      s.append(it2->first);
      s.append("\n");
    }
    return s;
  }
}
