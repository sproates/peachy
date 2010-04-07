#ifndef PEACHY_OBJECT_H
#define PEACHY_OBJECT_H

#include <string>

namespace peachy {

  class Class;
  class Log;

  class Object {

    public:

      Object(Log * logger, Class * clazz);
      virtual ~Object();
      std::string getClassName();
      Class * getClass();

    protected:

      Log * logger;
      Class * clazz;

    private:

      Object();
      Object(const Object & o);
      Object & operator = (const Object & o);
  };
}

#endif
