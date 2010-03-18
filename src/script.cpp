#include <iostream>
#include <typeinfo>

#include "environment.h"
#include "log.h"
#include "script.h"
#include "scriptsource.h"

namespace peachy {

  Script::Script(ScriptSource * scriptSource, Environment * environment) {
    Log::debug("Script constructor");
    setEnvironment(environment);
    setScriptSource(scriptSource);
  }

  Script::~Script() {
    Log::debug("Script destructor");
  }

  Script::Script(const Script & script) {
    Log::debug("Script copy constructor");
  }

  Script & Script::operator = (const Script & script) {
    Log::debug("Script assignment operator");
    if(this != &script) {
      Log::debug("The pointers are different, performing assignment");
      setEnvironment(script.environment);
      setScriptSource(script.scriptSource);
    } else {
      Log::debug("The pointers are the same, no further assignment necessary");
    }
    return *this;
  }

  void Script::setEnvironment(Environment * environment) {
    Log::debug("Script::setEnvironment");
    this->environment = environment;
  }

  void Script::setScriptSource(ScriptSource * scriptSource) {
    Log::debug("Script::setScriptSource");
    this->scriptSource = scriptSource;
  }

  Environment * Script::getEnvironment() {
    Log::debug("Script::getEnvironment");
    return environment;
  }

  ScriptSource * Script::getScriptSource() {
    Log::debug("Script::getScriptSource");
    return scriptSource;
  }

  void Script::run() {
    Log::debug("Script::run");
    while(scriptSource->hasMoreLines()) {
      Log::debug("Getting a line from the script source");
      Log::debug(scriptSource->getLine());
    }
    Log::debug("Reached end of script");
  }
}
