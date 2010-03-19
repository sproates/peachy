#ifndef PEACHY_SCRIPT_H
#define PEACHY_SCRIPT_H

namespace peachy {

  class Environment;
  class Log;
  class ScriptSource;

  class Script {

    public:

      Script(Log * logger, ScriptSource * scriptSource, Environment * environment);
      ~Script();
      void setScriptSource(ScriptSource * scriptSource);
      void setEnvironment(Environment * environment);
      Environment * getEnvironment();
      ScriptSource * getScriptSource();
      void run();

    protected:

    private:

      Environment * environment;
      ScriptSource * scriptSource;
      Log * logger;

      Script();
      Script(const Script & script);
      Script & operator = (const Script & script);
  };
}

#endif
