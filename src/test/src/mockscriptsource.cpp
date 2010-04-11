#include "mockscriptsource.h"

#include <string>

#include "log.h"

namespace peachy {

  namespace test {

    MockScriptSource::MockScriptSource(Log * logger) {
      logger->debug("MockScriptSource constructor");
      this->logger = logger;
    }

    MockScriptSource::~MockScriptSource() {
      logger->debug("MockScriptSource destructor");
    }

    std::string MockScriptSource::getLine() {
      logger->debug("MockScriptSource::getLine()");
      return std::string("");
    }

    bool MockScriptSource::hasMoreLines() {
      logger->debug("MockScriptSource::hasMoreLines()");
      return true;
    }
  }
}

