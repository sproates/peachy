#include "parser.h"

#include "log.h"
#include "tokensource.h"

namespace peachy {

  Parser::Parser(Log * logger, TokenSource * tokenSource) {
    logger->debug("Parser constructor");
    this->logger = logger;
    this->tokenSource = tokenSource;
  }

  Parser::~Parser() {
    logger->debug("Parser destructor");
  }
}

