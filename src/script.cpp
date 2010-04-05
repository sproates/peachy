#include "script.h"

#include <iostream>
#include <memory>

#include "environment.h"
#include "interpreter.h"
#include "log.h"
#include "parserexception.h"
#include "runtime.h"

namespace peachy {

  Script::Script(Log * logger, Environment * environment, Runtime * runtime,
		 Interpreter * interpreter) {
    logger->debug("Script constructor");
    this->logger = logger;
    this->environment = environment;
    this->runtime = runtime;
    this->interpreter = interpreter;
  }

  Script::~Script() {
    logger->debug("Script destructor");
  }

  void Script::run() {
    logger->debug("Script::run()");
    try {
      interpreter->run();
    } catch(ParserException & e) {
      logger->info("ParserException thrown");
      logger->info(e.what());
      return;
    }
    logger->debug("Reached end of script");
  }
}
