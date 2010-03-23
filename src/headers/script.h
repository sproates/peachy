#ifndef PEACHY_SCRIPT_H
#define PEACHY_SCRIPT_H

namespace peachy {

  class Environment;
  class Log;
  class Parser;
  class Runtime;

  class Script {

    public:

      Script(Log * logger, Environment * environment, Runtime * runtime,
	     Parser * parser);
      ~Script();

      Environment * getEnvironment();
      Runtime * getRuntime();
      Parser * getParser();

      void run();

    protected:

      Environment * environment;
      Log * logger;
      Parser * parser;
      Runtime * runtime;

    private:

      Script();
      Script(const Script & script);
      Script & operator = (const Script & script);
  };
}

#endif
