#include "script.h"

#include <iostream>

#include "environment.h"
#include "log.h"
#include "parser.h"
#include "runtime.h"

namespace peachy {

  Script::Script(Log * logger, Environment * environment, Runtime * runtime,
		 Parser * parser) {
    logger->debug("Script constructor");
    this->logger = logger;
    this->environment = environment;
    this->runtime = runtime;
    this->parser = parser;
  }

  Script::~Script() {
    logger->debug("Script destructor");
  }

  Environment * Script::getEnvironment() {
    logger->debug("Script::getEnvironment()");
    return environment;
  }

  Parser * Script::getParser() {
    logger->debug("Script::getParser()");
    return parser;
  }

  Runtime * Script::getRuntime() {
    logger->debug("Script::getRuntime()");
    return runtime;
  }

  void Script::run() {
    logger->debug("Script::run()");

    parser->parse();

    logger->debug("Reached end of script");
  }
}

