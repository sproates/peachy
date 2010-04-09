#include "types/int.h"

#include <stdexcept>
#include <string>

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

  void Int::add(Object * o) {
    if(o->getClassName().compare("Int") == 0) {
      Int * i = static_cast<Int*>(o);
      if(i == NULL) {
        throw std::runtime_error("An object had a class of Int but could not be cast to Int");
      }
      this->value += i->getValue();
    } else {
      throw std::runtime_error("Can only add an Int to an Int");
    }
  }
}
