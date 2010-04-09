#ifndef PEACHY_OBJECT_H
#define PEACHY_OBJECT_H

#include <string>

namespace peachy {

  class Class;
  class ClassFactory;
  class Log;

  class Object {

    public:

      Object(Log * logger, ClassFactory * classFactory);
      virtual ~Object();
      std::string getClassName();
      Class * getClass();
      virtual void add(Object * o) = 0;
      bool is(std::string className);
      bool is(Class * clazz);
      bool sameClass(Object * o);

    protected:

      Log * logger;
      Class * clazz;
      ClassFactory * classFactory;

    private:

      Object();
      Object(const Object & o);
      Object & operator = (const Object & o);
  };
}

#endif
