#include "testsuite.h"

#include <iostream>

namespace peachy {

  namespace test {

    TestSuite::TestSuite() {
      testCount = 0;
      failCount = 0;
      passCount = 0;
    }

    TestSuite::~TestSuite() {}

    int TestSuite::getTestCount() {
      return testCount;
    }

    int TestSuite::getPassCount() {
      return passCount;
    }

    int TestSuite::getFailCount() {
      return failCount;
    }

    void TestSuite::__assertThrows(bool thrown, const char * message,
      const char * file, int line) {
      testCount++;
      if(thrown) {
        passCount++;
      } else {
        failCount++;
        std::cout << "FAIL: " << message << std::endl;
        std::cout << "In " << file << " at line " << line << std::endl;
      }
    }

    void TestSuite::__assertEquals(bool expression, const char * message,
      const char * file, int line) {
      testCount++;
      if(expression) {
        passCount++;
      } else {
        failCount++;
        std::cout << "FAIL: " << message << std::endl;
        std::cout << "In " << file << " at line " << line << std::endl;
      }
    }

    
  }
}
