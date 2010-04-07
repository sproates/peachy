#ifndef PEACHY_CLASSFACTORY_H
#define PEACHY_CLASSFACTORY_H

#include <map>
#include <string>

namespace peachy {

  class Class;
  class Log;

  class ClassFactory {

    public:

      ClassFactory(Log * logger, Log * classLogger);
      virtual ~ClassFactory();
      Class * getClass(std::string name);

    protected:

      Log * logger;
      Log * classLogger;
      std::map<std::string,Class*> classes;
  };
}

#endif
