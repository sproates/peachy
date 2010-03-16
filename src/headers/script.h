#ifndef PEACHY_SCRIPT_H
#define PEACHY_SCRIPT_H

#include "environment.h"
#include "scriptsource.h"

namespace peachy {

  class Script {

    public:

      Script(ScriptSource *scriptSource, Environment *environment);
      ~Script();
      Script(const Script& s);
      Script& operator = (const Script& script);
      void setScriptSource(ScriptSource *scriptSource);
      void setEnvironment(Environment *environment);
      Environment *getEnvironment();
      ScriptSource *getScriptSource();
      void run();

    protected:

    private:

      Script();
      Environment *environment;
      ScriptSource *scriptSource;
  };
}

#endif
