#include <iostream>

#include "environment.h"
#include "lexer.h"
#include "log.h"
#include "runtime.h"
#include "token.h"

using namespace peachy;

int main() {

  Log * logger = new Log(&(std::cout));
  logger->info("Peachy test harness");

  Lexer * lexer = new Lexer(logger);
  delete lexer;

  Runtime * runtime = new Runtime(logger);
  delete runtime;

  Environment * environment = new Environment(logger);
  delete environment;

  Token * token = new Token(logger);
  delete token;

  logger->info("Test harness complete");
  delete logger;

  return 0;
}

