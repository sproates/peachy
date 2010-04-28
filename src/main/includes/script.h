#ifndef PEACHY_SCRIPT_H
#define PEACHY_SCRIPT_H

namespace peachy {

  class Environment;
  class ExpressionConsumer;
  class Log;
  class Runtime;

  class Script {

    public:

      Script(Log * logger, Environment * environment, Runtime * runtime,
	      ExpressionConsumer * expressionConsumer);
      ~Script();

      void run();

    protected:

      Environment * environment;
      ExpressionConsumer * expressionConsumer;
      Log * logger;
      Runtime * runtime;

    private:

      Script();
      Script(const Script & script);
      Script & operator = (const Script & script);
  };
}

#endif
