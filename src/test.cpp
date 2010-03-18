#include "lexer.h"
#include "log.h"

using namespace peachy;

int main(const int argc, const char ** argv) {

  Log::info("Peachy test harness");

  Lexer * lexer = new Lexer();
  delete lexer;

  return 0;
}

