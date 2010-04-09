#include "types/int.h"

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
}
