#ifndef PEACHY_SCOPE_H
#define PEACHY_SCOPE_H

#include <map>
#include <string>

namespace peachy {

  class Class;
  class Log;
  class Object;

  class Scope {

    public:

      Scope(Log * logger);
      virtual ~Scope();
      bool hasVariable(const std::string name);
      Object * getVariable(const std::string name);
      void addVariable(const std::string name, Object * value);
      void replaceVariable(const std::string name, Object * value);
      bool hasClass(const std::string name);
      void addClass(const std::string name, Class * clazz);
      Class * getClass(const std::string name);
      std::string toString();

    protected:

      Log * logger;
      std::map<std::string, Object*> variables;
      std::map<std::string, Class*> classes;

    private:

      Scope();
      Scope(const Scope & s);
      Scope & operator = (const Scope & s);
  };
}

#endif
