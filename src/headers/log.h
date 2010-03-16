#ifndef PEACHY_LOG_H
#define PEACHY_LOG_H

#include <string>

namespace peachy {
  class Log {
    public:
      static void debug(const char *message);
      static void debug(std::string message);
    private:
      Log();
  };
}

#endif
