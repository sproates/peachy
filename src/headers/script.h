#ifndef PEACHY_SCRIPT_H
#define PEACHY_SCRIPT_H

namespace peachy {

  class Environment;
  class Log;
  class Runtime;
  class ScriptSource;
  class TokenSource;

  class Script {

    public:

      Script(Log * logger, ScriptSource * scriptSource,
             Environment * environment, Runtime * runtime,
	     TokenSource * tokenSource);
      ~Script();

      void setEnvironment(Environment * environment);
      void setRuntime(Runtime * runtime);
      void setScriptSource(ScriptSource * scriptSource);
      void setTokenSource(TokenSource * tokenSource);

      Environment * getEnvironment();
      Runtime * getRuntime();
      ScriptSource * getScriptSource();
      TokenSource * getTokenSource();

      void run();

    protected:

    private:

      Environment * environment;
      Log * logger;
      Runtime * runtime;
      ScriptSource * scriptSource;
      TokenSource * tokenSource;

      Script();
      Script(const Script & script);
      Script & operator = (const Script & script);
  };
}

#endif
