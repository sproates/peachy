#include "testsuite.h"

#include <iostream>

namespace peachy {

  namespace test {

    TestSuite::TestSuite() {
      std::cout << "TestSuite constructor" << std::endl;
    }

    TestSuite::~TestSuite() {
      std::cout << "TestSuite destructor" << std::endl;
    }
  }
}
