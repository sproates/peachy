#include "environment.h"
#include "log.h"

namespace peachy {
  Environment::Environment() {
    Log::debug("Environment constructor");
  }

  Environment::~Environment() {
    Log::debug("Environment destructor");
  }

  Environment::Environment(const Environment& environment) {
    Log::debug("Environment copy constructor");
  }

  Environment& Environment::operator = (const Environment& environment) {
    Log::debug("Environment assignment operator");
    if(this != &environment) {
      Log::debug("The pointers are different, performing assignment");
    } else {
      Log::debug("The pointers are the same, no further assignment necessary");
    }
    return *this;
  }
}
