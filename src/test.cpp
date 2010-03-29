#include <iostream>
#include <string>

#include "environment.h"
#include "lexer.h"
#include "log.h"
#include "parser.h"
#include "peachyparser.h"
#include "runtime.h"
#include "script.h"
#include "scriptsource.h"
#include "stringscriptsource.h"
#include "tokensource.h"

using namespace peachy;

int main() {

  Log * logNoDebug = new Log(&std::cout);
  logNoDebug->enableDebug(false);
  logNoDebug->info("Peachy test harness");

  Log * logger = new Log(&std::cout);

  ScriptSource * scriptSource =
    new StringScriptSource(logNoDebug, std::string("i = 5\napple = -932"));
  Environment * environment = new Environment(logNoDebug);
  Runtime * runtime = new Runtime(logNoDebug);
  TokenSource * tokenSource = new Lexer(logNoDebug, scriptSource);
  Parser * parser = new PeachyParser(logger, tokenSource);
  Script * script = new Script(logNoDebug, environment, runtime, parser);

  script->run();

  delete script;
  delete parser;
  delete tokenSource;
  delete runtime;
  delete environment;
  delete scriptSource;
  delete logger;

  logNoDebug->info("Test harness complete");
  delete logNoDebug;

  return 0;
}
