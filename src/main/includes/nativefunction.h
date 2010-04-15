#ifndef PEACHY_NATIVEFUNCTION_H
#define PEACHY_NATIVEFUNCTION_H

#include <list>
#include <string>

namespace peachy {

  class Object;

  class NativeFunction {

    public:

      NativeFunction(std::string name);
      virtual ~NativeFunction();
      virtual Object * call(std::list<Object *> parameters) = 0;

    protected:

      std::string name;

    private:

      NativeFunction();
      NativeFunction(const NativeFunction & n);
      NativeFunction & operator = (const NativeFunction & n);
  };
}

#endif
