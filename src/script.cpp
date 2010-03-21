#include "script.h"

#include <iostream>

#include "environment.h"
#include "lexer.h"
#include "log.h"
#include "scriptsource.h"

namespace peachy {

  Script::Script(Log * logger, ScriptSource * scriptSource,
                 Environment * environment, Lexer * lexer) {
    logger->debug("Script constructor");
    this->logger = logger;
    setEnvironment(environment);
    setLexer(lexer);
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

