#ifndef PEACHY_LOG_H
#define PEACHY_LOG_H

#include <ostream>
#include <string>

namespace peachy {

  class Log {

    public:

      Log(std::ostream * outputStream);

      void debug(const char *message);
      void debug(std::string message);

      void info(const char *message);
      void info(std::string message);

      void warning(const char * message);
      void warning(std::string message);

      void error(const char * message);
      void error(std::string message);

      void fatal(const char * message);
      void fatal(std::string message);

    protected:

      std::ostream * outputStream;

    private:

      Log();
  };
}

#endif
