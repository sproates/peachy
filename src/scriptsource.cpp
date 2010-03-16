#include "log.h"
#include "scriptsource.h"

namespace peachy {

  ScriptSource::~ScriptSource() {
    Log::debug("ScriptSource destructor");
  }

}
