#ifndef PEACHY_SCRIPT_H
#define PEACHY_SCRIPT_H

namespace peachy {

  class Environment;
  class Lexer;
  class Log;
  class ScriptSource;

  class Script {

    public:

      Script(Log * logger, ScriptSource * scriptSource,
             Environment * environment, Lexer * lexer);
      ~Script();

      void setEnvironment(Environment * environment);
      void setLexer(Lexer * lexer);
      void setScriptSource(ScriptSource * scriptSource);

      Environment * getEnvironment();
      Lexer * getLexer();
      ScriptSource * getScriptSource();

      void run();

    protected:

    private:

      Environment * environment;
      Lexer * lexer;
      Log * logger;
      ScriptSource * scriptSource;

      Script();
      Script(const Script & script);
      Script & operator = (const Script & script);
  };
}

#endif
