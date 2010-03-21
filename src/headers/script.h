#ifndef PEACHY_SCRIPT_H
#define PEACHY_SCRIPT_H

namespace peachy {

  class Environment;
  class Lexer;
  class Log;
  class Runtime;
  class ScriptSource;

  class Script {

    public:

      Script(Log * logger, ScriptSource * scriptSource,
             Environment * environment, Runtime * runtime, Lexer * lexer);
      ~Script();

      void setEnvironment(Environment * environment);
      void setLexer(Lexer * lexer);
      void setRuntime(Runtime * runtime);
      void setScriptSource(ScriptSource * scriptSource);

      Environment * getEnvironment();
      Lexer * getLexer();
      Runtime * getRuntime();
      ScriptSource * getScriptSource();

      void run();

    protected:

    private:

      Environment * environment;
      Lexer * lexer;
      Log * logger;
      Runtime * runtime;
      ScriptSource * scriptSource;

      Script();
      Script(const Script & script);
      Script & operator = (const Script & script);
  };
}

#endif
