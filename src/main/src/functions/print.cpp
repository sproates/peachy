#include "functions/print.h"

#include <iostream>
#include <list>
#include <string>
#include <typeinfo>

#include "object.h"

namespace peachy {

  Print::~Print() {}

  Object * Print::call(std::list<Object*> parameters) {
    Object * o;
    std::list<Object*>::iterator it = parameters.begin();
    while(it != parameters.end()) {
      o = *it;
      std::cout << o->toString() << std::endl;
      ++it;
    }
    return o;
  }
}
