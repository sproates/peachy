#include "nativefunction.h"

#include <list>
#include <string>

#include "object.h"

namespace peachy {

  NativeFunction::NativeFunction(std::string name) {
    this->name = name;
  }

  NativeFunction::~NativeFunction() {}
}
