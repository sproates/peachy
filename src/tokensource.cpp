#include "tokensource.h"

#include "log.h"
#include "scriptsource.h"
#include "tokenfactory.h"

namespace peachy {

  TokenSource::TokenSource(Log * logger, TokenFactory * tokenFactory,
                           ScriptSource * scriptSource) {
    logger->debug("TokenSource constructor");
    this->logger = logger;
    this->tokenFactory = tokenFactory;
    this->scriptSource = scriptSource;
  }

  TokenSource::~TokenSource() {
    logger->debug("TokenSource destructor");
  }
}
