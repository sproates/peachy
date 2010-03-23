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

  Token * token;

  token = new Token(logger);
  delete token;

  token = new Token(logger, TOKEN_NEWLINE);
  logger->info(token->toString());
  delete token;

  token = new Token(logger, TOKEN_INTEGER, std::string("5"));
  logger->info(token->toString());
  delete token;

  ScriptSource * scriptSource =
    new StringScriptSource(logger, std::string(""));
  Environment * environment = new Environment(logger);
  Runtime * runtime = new Runtime(logger);
  TokenSource * tokenSource = new Lexer(logger, scriptSource);
  Script * script = new Script(logger, environment, runtime, tokenSource);
  Parser * parser = new Parser(logger, script);

  token = tokenSource->nextToken();
  delete token;

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

