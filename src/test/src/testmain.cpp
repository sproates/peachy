#include <iostream>

#include "testsuite.h"
#include "lexersuite.h"

int main() {

  std::cout << "Peachy test suite" << std::endl;

  int testCount = 0;
  int passCount = 0;
  int failCount = 0;
  
  peachy::test::TestSuite * lexerSuite = new peachy::test::LexerSuite();
  lexerSuite->run();
  testCount += lexerSuite->getTestCount();
  passCount += lexerSuite->getPassCount();
  failCount += lexerSuite->getFailCount();
  delete lexerSuite;

  std::cout << "Test suite complete" << std::endl;

  std::cout << "Ran " << testCount << " tests" << std::endl;
  std::cout << "Passed " << passCount << std::endl;
  std::cout << "Failed " << failCount << std::endl;

  return failCount;
}
