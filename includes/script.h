#ifndef PEACHY_SCRIPT_H
#define PEACHY_SCRIPT_H

namespace peachy {

  class Environment;
  class Interpreter;
  class Log;
  class Runtime;

  class Script {

    public:

      Script(Log * logger, Environment * environment, Runtime * runtime,
	     Interpreter * interpreter);
      ~Script();

      void run();

    protected:

      Environment * environment;
      Interpreter * interpreter;
      Log * logger;
      Runtime * runtime;

    private:

      Script();
      Script(const Script & script);
      Script & operator = (const Script & script);
  };
}

#endif
