#include "scope.h"

#include <map>
#include <string>

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

  bool Scope::has(const std::string name) {
    logger->debug("Scope::has()");
    return (variables.find(name) != variables.end());
  }

  Object * Scope::get(const std::string name) {
    logger->debug("Scope::get()");
    return variables.find(name)->second;
  }

  void Scope::add(const std::string name, Object * value) {
    logger->debug("Scope::add()");
    variables[name] = value;
  }

  void Scope::replace(const std::string name, Object * value) {
    logger->debug("Scope::replace()");
    variables[name] = value;
  }
}
