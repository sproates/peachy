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

  Log * logger = new Log(&(std::cout));
  logger->info("Peachy test harness");

  ScriptSource * scriptSource =
    new StringScriptSource(logger, std::string("i = 5\napple = 66"));
  Environment * environment = new Environment(logger);
  Runtime * runtime = new Runtime(logger);
  TokenSource * tokenSource = new Lexer(logger, scriptSource);
  Parser * parser = new PeachyParser(logger, tokenSource);
  Script * script = new Script(logger, environment, runtime, parser);

  script->run();

  delete script;
  delete parser;
  delete tokenSource;
  delete runtime;
  delete environment;
  delete scriptSource;

  logger->info("Test harness complete");
  delete logger;

  return 0;
}
