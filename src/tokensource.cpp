#include "tokensource.h"

#include "log.h"

namespace peachy {

  TokenSource::TokenSource(Log * logger) {
    logger->debug("TokenSource constructor");
    this->logger = logger;
  }

  TokenSource::~TokenSource() {
    logger->debug("TokenSource destructor");
  }
}

