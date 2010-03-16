#include "runtime.h"
#include "log.h"

namespace peachy {

  Runtime::Runtime() {
    Log::debug("Runtime constructor");
  }

  Runtime::~Runtime() {
    Log::debug("Runtime destructor");
  }

  Runtime::Runtime(const Runtime& runtime) {
    Log::debug("Runtime copy constructor");
  }
}
