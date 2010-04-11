#ifndef PEACHY_CLASS_H
#define PEACHY_CLASS_H

#include <string>

namespace peachy {

  class Log;

  class Class {

    public:

      Class(Log * logger, std::string name);
      virtual ~Class();
      std::string getName();

    protected:

      Log * logger;
      std::string name;

    private:

      Class();
      Class(const Class & c);
      Class & operator = (const Class & c);
  };
}

#endif
