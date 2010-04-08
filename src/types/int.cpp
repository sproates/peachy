#include "types/int.h"

#include "log.h"
#include "object.h"

namespace peachy {

  Int::~Int() {
    logger->debug("Int destructor");
  }
}
