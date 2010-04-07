#ifndef PEACHY_STRING_H
#define PEACHY_STRING_H

#include <string>

namespace peachy {

  class Log;

  class String {

    public:

      String(Log * logger, std::string value);
      virtual ~String();
      std::string getValue();

    protected:

      Log * logger;
      std::string value;

    private:

      String();
      String(const String & s);
      String & operator = (const String & s);
  };
}

#endif
