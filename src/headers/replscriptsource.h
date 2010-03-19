#ifndef PEACHY_REPLSCRIPTSOURCE_H
#define PEACHY_REPLSCRIPTSOURCE_H

#include "scriptsource.h"

namespace peachy {

  class Log;

  class REPLScriptSource : public ScriptSource {

    public:

      REPLScriptSource(Log * logger);
      ~REPLScriptSource();
      std::string getLine();
      bool hasMoreLines();

    protected:

      std::string currentLine;
      std::istream * stream;

    private:

      Log * logger;
      REPLScriptSource();
      REPLScriptSource(const REPLScriptSource & replScriptSource);
      REPLScriptSource & operator = (const REPLScriptSource & replScriptSource);
  };

}

#endif
