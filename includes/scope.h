#ifndef PEACHY_SCOPE_H
#define PEACHY_SCOPE_H

#include <map>
#include <string>

namespace peachy {

  class Log;
  class Object;

  class Scope {

    public:

      Scope(Log * logger);
      virtual ~Scope();
      bool has(const std::string name);
      Object * get(const std::string name);
      void add(const std::string name, Object * value);
      void replace(const std::string name, Object * value);
      std::string toString();

    protected:

      Log * logger;
      std::map<std::string, Object*> variables;

    private:

      Scope();
      Scope(const Scope & s);
      Scope & operator = (const Scope & s);
  };
}

#endif
