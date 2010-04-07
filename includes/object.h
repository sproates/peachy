#ifndef PEACHY_OBJECT_H
#define PEACHY_OBJECT_H

namespace peachy {

  class Log;

  class Object {

    public:

      Object(Log * logger);
      virtual ~Object();

    protected:

      Log * logger;

    private:

      Object();
      Object(const Object & o);
      Object & operator = (const Object & o);
  };
}

#endif
