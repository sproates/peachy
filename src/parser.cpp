#include "parser.h"

#include "log.h"
#include "script.h"

namespace peachy {

  Parser::Parser(Log * logger, Script * script) {
    logger->debug("Parser constructor");
    this->logger = logger;
    this->script = script;
  }

  Parser::~Parser() {
    logger->debug("Parser destructor");
  }
}

