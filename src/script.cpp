#include "script.h"

#include <iostream>

#include "environment.h"
#include "lexer.h"
#include "log.h"
#include "runtime.h"
#include "scriptsource.h"

namespace peachy {

  Script::Script(Log * logger, ScriptSource * scriptSource,
                 Environment * environment, Runtime * runtime, Lexer * lexer) {
    logger->debug("Script constructor");
    this->logger = logger;
    setEnvironment(environment);
    setLexer(lexer);
    setRuntime(runtime);
    setScriptSource(scriptSource);
  }

  Script::~Script() {
    logger->debug("Script destructor");
  }

  void Script::setEnvironment(Environment * environment) {
    logger->debug("Script::setEnvironment()");
    this->environment = environment;
  }

  void Script::setLexer(Lexer * lexer) {
    logger->debug("Script::setLexer()");
    this->lexer = lexer;
  }

  void Script::setRuntime(Runtime * runtime) {
    logger->debug("Script::setRuntime()");
    this->runtime = runtime;
  }

  void Script::setScriptSource(ScriptSource * scriptSource) {
    logger->debug("Script::setScriptSource()");
    this->scriptSource = scriptSource;
  }

  Environment * Script::getEnvironment() {
    logger->debug("Script::getEnvironment()");
    return environment;
  }

  Lexer * Script::getLexer() {
    logger->debug("Script::getLexer()");
    return lexer;
  }

  Runtime * Script::getRuntime() {
    logger->debug("Script::getRuntime()");
    return runtime;
  }

  ScriptSource * Script::getScriptSource() {
    logger->debug("Script::getScriptSource()");
    return scriptSource;
  }

  void Script::run() {
    logger->debug("Script::run()");
    while(scriptSource->hasMoreLines()) {
      logger->debug("Getting a line from the script source");
      logger->debug(scriptSource->getLine());
    }
    logger->debug("Reached end of script");
  }
}

