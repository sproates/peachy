#ifndef PEACHY_SCRIPT_H
#define PEACHY_SCRIPT_H

namespace peachy {

  class Environment;
  class ExpressionSource;
  class Log;
  class Runtime;

  class Script {

    public:

      Script(Log * logger, Environment * environment, Runtime * runtime,
	     ExpressionSource * expressionSource);
      ~Script();

      void run();

    protected:

      Environment * environment;
      ExpressionSource * expressionSource;
      Log * logger;
      Runtime * runtime;

    private:

      Script();
      Script(const Script & script);
      Script & operator = (const Script & script);
  };
}

#endif
