#ifndef PEACHY_STRINGSCRIPTSOURCE_H
#define PEACHY_STRINGSCRIPTSOURCE_H

#include "scriptsource.h"

namespace peachy {

  class StringScriptSource : public ScriptSource {

    public:

      StringScriptSource(std::string scriptString);
      StringScriptSource(char * scriptString);
      ~StringScriptSource();
      std::string getLine();
      bool hasMoreLines();

    protected:

      std::istringstream * stream;
      std::string currentLine;

    private:

      StringScriptSource();
      void construct(std::string scriptString);
      StringScriptSource(const StringScriptSource & stringScriptSource);
      StringScriptSource & operator = (const StringScriptSource & stringScriptSource);
  };

}

#endif
