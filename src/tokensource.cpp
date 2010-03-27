#include "tokensource.h"

#include "log.h"
#include "scriptsource.h"

namespace peachy {

  TokenSource::TokenSource(Log * logger, ScriptSource * scriptSource) {
    logger->debug("TokenSource constructor");
    this->logger = logger;
    this->scriptSource = scriptSource;
  }

  TokenSource::~TokenSource() {
    logger->debug("TokenSource destructor");
  }
}
