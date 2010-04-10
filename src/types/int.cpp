#include "types/int.h"

#include <iostream>
#include <stdexcept>
#include <string>

#include "class.h"
#include "classfactory.h"
#include "log.h"
#include "object.h"

namespace peachy {

  Int::~Int() {
    logger->debug("Int destructor");
  }

  int Int::getValue() {
    return value;
  }

  void Int::setValue(int value) {
    this->value = value;
  }

  Object * Int::add(Object * o) {
    logger->debug("Int::add()");
    if(o->getClassName().compare("Int") == 0) {
      Int * i = static_cast<Int*>(o);
      if(i == NULL) {
        throw std::runtime_error("An object had a class of Int but could not be cast to Int");
      }
      int newValue = this->value + i->getValue();
      return new Int(logger, classFactory, newValue);
    } else {
      throw std::runtime_error("Can only add an Int to an Int");
    }
  }

  Object * Int::clone() {
    logger->debug("Int::clone()");
    return new Int(logger, classFactory, value);
  }
}
