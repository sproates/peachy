#ifndef PEACHY_CLASS_H
#define PEACHY_CLASS_H

namespace peachy {

  class Log;

  class Class {

    public:

      Class(Log * logger);
      virtual ~Class();

    protected:

      Log * logger;

    private:

      Class();
      Class(const Class & c);
      Class & operator = (const Class & c);
  };
}

#endif
