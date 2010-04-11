#include <iostream>

#include "testsuite.h"
#include "lexersuite.h"

int main() {

  std::cout << "Peachy test suite" << std::endl;

  peachy::test::TestSuite * lexerSuite = new peachy::test::LexerSuite();
  lexerSuite->run();
  delete lexerSuite;

  std::cout << "Test suite complete" << std::endl;

  return 0;
}
