#ifndef PEACHY_OBJECT_H
#define PEACHY_OBJECT_H

namespace peachy {

  class Class;
  class Log;

  class Object {

    public:

      Object(Log * logger);
      virtual ~Object();
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
