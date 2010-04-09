#include "types/string.h"

#include <stdexcept>
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

  void String::add(Object * o) {
    if(o->getClassName().compare("String") == 0) {
      String * s = static_cast<String*>(o);
      if(s == NULL) {
        throw std::runtime_error("An object had a class of String but could not be cast to String");
      }
      this->value = this->value.append(s->getValue());
    } else {
      throw std::runtime_error("Can only add a String to a String");
    }
  }
}
