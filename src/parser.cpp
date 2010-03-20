#include "parser.h"

#include "log.h"

namespace peachy {

  Parser::Parser(Log * logger) {
    logger->debug("Parser constructor");
    this->logger = logger;
  }

  Parser::~Parser() {
    logger->debug("Parser destructor");
  }
}

