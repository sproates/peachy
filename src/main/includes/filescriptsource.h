#ifndef PEACHY_FILESCRIPTSOURCE_H
#define PEACHY_FILESCRIPTSOURCE_H

#include "istreamscriptsource.h"

namespace peachy {

  class Log;

  class FileScriptSource : public IStreamScriptSource {

    public:

      FileScriptSource(Log * logger, std::string filename);
      FileScriptSource(Log * logger, const char * filename);
      ~FileScriptSource();

    private:

      void construct(Log * logger, const char * filename);
      FileScriptSource();
      FileScriptSource(const FileScriptSource & fileScriptSource);
      FileScriptSource & operator = (const FileScriptSource & fileScriptSource);
  };

}

#endif
