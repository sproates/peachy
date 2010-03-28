#ifndef PEACHY_SCRIPTSOURCE_H
#define PEACHY_SCRIPTSOURCE_H

#include <string>

namespace peachy {

  class ScriptSource {

    public:

      virtual ~ScriptSource();
      virtual std::string getLine() = 0;
      virtual bool hasMoreLines() = 0;
  };

}

#endif
