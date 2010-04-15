#ifndef PEACHY_PRINT_H
#define PEACHY_PRINT_H

#include <list>
#include <string>

#include "nativefunction.h"

namespace peachy {

  class Object;

  class Print : public NativeFunction {

    public:

      Print() : NativeFunction(std::string("print")) {}
      ~Print();
      Object * call(std::list<Object *> parameters);

    private:

      Print(const Print & p);
      Print & operator = (const Print & p);
  };
}

#endif
