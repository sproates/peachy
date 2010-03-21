#include <iostream>
#include <string>

#include "environment.h"
#include "lexer.h"
#include "log.h"
#include "parser.h"
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

  Token * newLineToken = new Token(logger, TOKEN_NEWLINE, std::string(""));
  logger->info(newLineToken->toString());
  delete newLineToken;

  Token * integerToken = new Token(logger, TOKEN_INTEGER, std::string("5"));
  logger->info(integerToken->toString());
  delete integerToken;

  Parser * parser = new Parser(logger);
  delete parser;

  logger->info("Test harness complete");
  delete logger;

  return 0;
}

