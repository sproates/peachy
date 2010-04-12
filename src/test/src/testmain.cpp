#include <iostream>

#include "expressionfactorysuite.h"
#include "testsuite.h"
#include "lexersuite.h"
#include "tokenfactorysuite.h"

int main() {

  std::cout << "Peachy test suite" << std::endl;

  int testCount = 0;
  int passCount = 0;
  int failCount = 0;
  
  peachy::test::TestSuite * suite;

  suite = new peachy::test::ExpressionFactorySuite();
  suite->run();
  testCount += suite->getTestCount();
  passCount += suite->getPassCount();
  failCount += suite->getFailCount();

  suite = new peachy::test::TokenFactorySuite();
  suite->run();
  testCount += suite->getTestCount();
  passCount += suite->getPassCount();
  failCount += suite->getFailCount();

  suite = new peachy::test::LexerSuite();
  suite->run();
  testCount += suite->getTestCount();
  passCount += suite->getPassCount();
  failCount += suite->getFailCount();

  delete suite;

  std::cout << "Test suite complete" << std::endl;

  std::cout << "Ran " << testCount << " tests" << std::endl;
  std::cout << "Passed " << passCount << std::endl;
  std::cout << "Failed " << failCount << std::endl;

  return failCount;
}
