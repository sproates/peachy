#include <iostream>
#include <stdexcept>
#include <string>

#include "environment.h"
#include "expressionfactory.h"
#include "expressionsource.h"
#include "filescriptsource.h"
#include "interpreter.h"
#include "lexer.h"
#include "log.h"
#include "nullostream.h"
#include "parser.h"
#include "runtime.h"
#include "script.h"
#include "scriptsource.h"
#include "tokenfactory.h"
#include "tokensource.h"

using namespace peachy;

int main() {

  NullOStream * nullOStream = new NullOStream;
  Log * nullLogger = new Log(nullOStream);
  Log * debugLogger = new Log(&std::cout);

  debugLogger->info("Peachy test harness");

  ScriptSource * scriptSource;

  try {
    scriptSource = new FileScriptSource(nullLogger, "test.peachy");
  } catch(std::runtime_error e) {
    debugLogger->info("Unable to acquire script source");
    goto shortexit;
  }
  Environment * environment = new Environment(nullLogger);
  Runtime * runtime = new Runtime(nullLogger);
  TokenFactory * tokenFactory = new TokenFactory(nullLogger, nullLogger);
  TokenSource * tokenSource = new Lexer(nullLogger, tokenFactory, scriptSource);
  ExpressionFactory * expressionFactory = new ExpressionFactory(nullLogger,
    nullLogger);
  ExpressionSource * expressionSource = new Parser(debugLogger,
    expressionFactory, tokenSource);
  Interpreter * interpreter = new Interpreter(nullLogger, expressionSource);
  Script * script = new Script(debugLogger, environment, runtime, interpreter);

  script->run();

  delete script;
  delete interpreter;
  delete expressionSource;
  delete expressionFactory;
  delete tokenSource;
  delete tokenFactory;
  delete runtime;
  delete environment;
  delete scriptSource;

shortexit:

  delete nullLogger;
  delete nullOStream;

  debugLogger->info("Test harness complete");
  delete debugLogger;

  return 0;
}
