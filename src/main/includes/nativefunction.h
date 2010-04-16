#ifndef PEACHY_NATIVEFUNCTION_H
#define PEACHY_NATIVEFUNCTION_H

#include <list>
#include <string>

namespace peachy {

  class Object;

  class NativeFunction {

    public:

      NativeFunction();
      virtual ~NativeFunction();
      virtual Object * call(std::list<Object *> parameters) = 0;

    private:

      NativeFunction(const NativeFunction & n);
      NativeFunction & operator = (const NativeFunction & n);
  };
}

#endif
