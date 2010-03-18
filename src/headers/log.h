#ifndef PEACHY_LOG_H
#define PEACHY_LOG_H

#include <string>

namespace peachy {

  class Log {

    public:

      static void debug(const char *message);
      static void debug(std::string message);

      static void info(const char *message);
      static void info(std::string message);

    private:

      // Constructor is private as this is just a bunch of
      // static methods.
      Log();
  };
}

#endif
