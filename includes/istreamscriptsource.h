#ifndef PEACHY_ISTREAMSCRIPTSOURCE_H
#define PEACHY_ISTREAMSCRIPTSOURCE_H

#include "scriptsource.h"

namespace peachy {

  class Log;

  class IStreamScriptSource : public ScriptSource {

    public:

      IStreamScriptSource(Log * logger, std::istream * stream);
      virtual ~IStreamScriptSource();
      bool hasMoreLines();
      std::string getLine();

    protected:

      std::istream * stream;
      std::string currentLine;
      Log * logger;

    private:

      IStreamScriptSource();
      IStreamScriptSource(const IStreamScriptSource & s);
      IStreamScriptSource & operator = (const IStreamScriptSource & s);
  };
}

#endif
