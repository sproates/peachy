#ifndef PEACHY_STRINGSCRIPTSOURCE_H
#define PEACHY_STRINGSCRIPTSOURCE_H

#include "scriptsource.h"

namespace peachy {

  class Log;

  class StringScriptSource : public ScriptSource {

    public:

      StringScriptSource(Log * logger, std::string scriptString);
      StringScriptSource(Log * logger, char * scriptString);
      ~StringScriptSource();
      std::string getLine();
      bool hasMoreLines();

    protected:

      std::istringstream * stream;
      std::string currentLine;

    private:

      Log * logger;
      StringScriptSource();
      void construct(Log * logger, std::string scriptString);
      StringScriptSource(const StringScriptSource & stringScriptSource);
      StringScriptSource & operator = (const StringScriptSource & stringScriptSource);
  };

}

#endif
