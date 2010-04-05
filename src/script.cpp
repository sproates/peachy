#include "script.h"

#include <iostream>
#include <memory>

#include "environment.h"
#include "interpreter.h"
#include "interpreterexception.h"
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
    } catch(ParserException & pe) {
      logger->info("ParserException thrown");
      logger->info(pe.what());
      return;
    } catch(InterpreterException & ie) {
      logger->info("InterpreterException thrown");
      logger->info(ie.what());
      return;
    } catch(...) {
      logger->debug("Something bad happened");
      return;
    }
    logger->debug("Reached end of script");
  }
}
