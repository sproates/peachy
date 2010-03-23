#include "script.h"

#include <iostream>

#include "environment.h"
#include "log.h"
#include "runtime.h"
#include "tokensource.h"

namespace peachy {

  Script::Script(Log * logger, Environment * environment, Runtime * runtime,
		 TokenSource * tokenSource) {
    logger->debug("Script constructor");
    this->logger = logger;
    setEnvironment(environment);
    setRuntime(runtime);
    setTokenSource(tokenSource);
  }

  Script::~Script() {
    logger->debug("Script destructor");
  }

  void Script::setEnvironment(Environment * environment) {
    logger->debug("Script::setEnvironment()");
    this->environment = environment;
  }

  void Script::setRuntime(Runtime * runtime) {
    logger->debug("Script::setRuntime()");
    this->runtime = runtime;
  }

  void Script::setTokenSource(TokenSource * tokenSource) {
    logger->debug("Script::setTokenSource()");
    this->tokenSource = tokenSource;
  }

  Environment * Script::getEnvironment() {
    logger->debug("Script::getEnvironment()");
    return environment;
  }

  Runtime * Script::getRuntime() {
    logger->debug("Script::getRuntime()");
    return runtime;
  }

  TokenSource * Script::getTokenSource() {
    logger->debug("Script::getTokenSource()");
    return tokenSource;
  }

  void Script::run() {
    logger->debug("Script::run()");

/*
    while(scriptSource->hasMoreLines()) {
      logger->debug("Getting a line from the script source");
      logger->debug(scriptSource->getLine());
    }
*/

    logger->debug("Reached end of script");
  }
}

