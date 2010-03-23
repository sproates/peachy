#ifndef PEACHY_SCRIPT_H
#define PEACHY_SCRIPT_H

namespace peachy {

  class Environment;
  class Log;
  class Runtime;
  class TokenSource;

  class Script {

    public:

      Script(Log * logger, Environment * environment, Runtime * runtime,
	     TokenSource * tokenSource);
      ~Script();

      void setEnvironment(Environment * environment);
      void setRuntime(Runtime * runtime);
      void setTokenSource(TokenSource * tokenSource);

      Environment * getEnvironment();
      Runtime * getRuntime();
      TokenSource * getTokenSource();

      void run();

    protected:

      Environment * environment;
      Log * logger;
      Runtime * runtime;
      TokenSource * tokenSource;

    private:

      Script();
      Script(const Script & script);
      Script & operator = (const Script & script);
  };
}

#endif
