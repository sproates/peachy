#ifndef PEACHY_FILESCRIPTSOURCE_H
#define PEACHY_FILESCRIPTSOURCE_H

#include "scriptsource.h"

namespace peachy {

  class Log;

  class FileScriptSource : public ScriptSource {

    public:

      FileScriptSource(Log * logger, std::string filename);
      FileScriptSource(Log * logger, const char * filename);
      ~FileScriptSource();
      std::string getLine();
      bool hasMoreLines();

    protected:

      std::string currentLine;
      std::ifstream * stream;

    private:

      Log * logger;
      void construct(Log * logger, const char * filename);
      FileScriptSource();
      FileScriptSource(const FileScriptSource & fileScriptSource);
      FileScriptSource & operator = (const FileScriptSource & fileScriptSource);
  };

}

#endif
