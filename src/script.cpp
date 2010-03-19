#include "script.h"

#include <iostream>

#include "environment.h"
#include "log.h"
#include "scriptsource.h"

namespace peachy {

  Script::Script(Log * logger, ScriptSource * scriptSource, Environment * environment) {
    this->logger = logger;
    this->logger->debug("Script constructor");
    setEnvironment(environment);
    setScriptSource(scriptSource);
  }

  Script::~Script() {
    logger->debug("Script destructor");
  }

  void Script::setEnvironment(Environment * environment) {
    logger->debug("Script::setEnvironment");
    this->environment = environment;
  }

  void Script::setScriptSource(ScriptSource * scriptSource) {
    logger->debug("Script::setScriptSource");
    this->scriptSource = scriptSource;
  }

  Environment * Script::getEnvironment() {
    logger->debug("Script::getEnvironment");
    return environment;
  }

  ScriptSource * Script::getScriptSource() {
    logger->debug("Script::getScriptSource");
    return scriptSource;
  }

  void Script::run() {
    logger->debug("Script::run");
    while(scriptSource->hasMoreLines()) {
      logger->debug("Getting a line from the script source");
      logger->debug(scriptSource->getLine());
    }
    logger->debug("Reached end of script");
  }
}

