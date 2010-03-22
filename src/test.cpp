#include <iostream>
#include <string>

#include "environment.h"
#include "lexer.h"
#include "log.h"
#include "parser.h"
#include "runtime.h"
#include "script.h"
#include "scriptsource.h"
#include "stringscriptsource.h"
#include "token.h"
#include "tokensource.h"
#include "tokentype.h"

using namespace peachy;

int main() {

  Log * logger = new Log(&(std::cout));
  logger->info("Peachy test harness");

  Token * token = new Token(logger);
  delete token;

  Token * newLineToken = new Token(logger, TOKEN_NEWLINE);
  logger->info(newLineToken->toString());
  delete newLineToken;

  Token * integerToken = new Token(logger, TOKEN_INTEGER, std::string("5"));
  logger->info(integerToken->toString());
  delete integerToken;

  ScriptSource * scriptSource =
    new StringScriptSource(logger, std::string(""));
  Environment * environment = new Environment(logger);
  Runtime * runtime = new Runtime(logger);
  TokenSource * tokenSource = new Lexer(logger);
  Script * script = new Script(logger, scriptSource, environment, runtime,
                               tokenSource);
  Parser * parser = new Parser(logger, script);

  delete parser;
  delete script;
  delete tokenSource;
  delete runtime;
  delete environment;
  delete scriptSource;

  logger->info("Test harness complete");
  delete logger;

  return 0;
}

