#ifndef PEACHY_FILESCRIPTSOURCE_H
#define PEACHY_FILESCRIPTSOURCE_H

#include "scriptsource.h"

namespace peachy {

  class FileScriptSource : public ScriptSource {

    public:

      FileScriptSource(std::string filename);
      FileScriptSource(const char * filename);
      ~FileScriptSource();
      std::string getLine();
      bool hasMoreLines();

    protected:

      std::string currentLine;
      std::ifstream * stream;

    private:

      void construct(const char * filename);
      FileScriptSource();
      FileScriptSource(const FileScriptSource & fileScriptSource);
      FileScriptSource & operator = (const FileScriptSource & fileScriptSource);
  };

}

#endif
