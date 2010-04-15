#include "functions/print.h"

#include <iostream>
#include <list>
#include <string>

#include "object.h"

namespace peachy {

  Print::~Print() {}

  Object * Print::call(std::list<Object*> parameters) {
    Object * o;
    for(std::list<Object*>::iterator it = parameters.begin(); it != parameters.end(); it++) {
      o = *it;
      std::cout << o->toString();
    }
    return o;
  }
}
