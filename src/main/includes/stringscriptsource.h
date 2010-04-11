#ifndef PEACHY_STRINGSCRIPTSOURCE_H
#define PEACHY_STRINGSCRIPTSOURCE_H

#include "istreamscriptsource.h"

namespace peachy {

  class Log;

  class StringScriptSource : public IStreamScriptSource {

    public:

      StringScriptSource(Log * logger, std::string scriptString);
      StringScriptSource(Log * logger, char * scriptString);
      ~StringScriptSource();

    private:

      StringScriptSource();
      void construct(Log * logger, std::string scriptString);
      StringScriptSource(const StringScriptSource & s);
      StringScriptSource & operator = (const StringScriptSource & s);
  };

}

#endif
