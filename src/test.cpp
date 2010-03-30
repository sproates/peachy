#include <iostream>
#include <string>

#include "environment.h"
#include "lexer.h"
#include "log.h"
#include "nullostream.h"
#include "parser.h"
#include "peachyparser.h"
#include "runtime.h"
#include "script.h"
#include "scriptsource.h"
#include "stringscriptsource.h"
#include "tokensource.h"

using namespace peachy;

int main() {

  NullOStream * nullOStream = new NullOStream;
  Log * nullLogger = new Log(nullOStream);
  Log * debugLogger = new Log(&std::cout);

  debugLogger->info("Peachy test harness");

  ScriptSource * scriptSource =
    new StringScriptSource(nullLogger, std::string("i = 5\napple = -932"));
  Environment * environment = new Environment(nullLogger);
  Runtime * runtime = new Runtime(nullLogger);
  TokenSource * tokenSource = new Lexer(debugLogger, scriptSource);
  Parser * parser = new PeachyParser(debugLogger, tokenSource);
  Script * script = new Script(nullLogger, environment, runtime, parser);

  script->run();

  delete script;
  delete parser;
  delete tokenSource;
  delete runtime;
  delete environment;
  delete scriptSource;
  delete nullLogger;
  delete nullOStream;

  debugLogger->info("Test harness complete");
  delete debugLogger;

  return 0;
}
