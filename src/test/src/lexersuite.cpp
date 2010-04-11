#include "lexersuite.h"

#include <iostream>

#include "testsuite.h"

namespace peachy {

  namespace test {

    LexerSuite::~LexerSuite() {
      std::cout << "LexerSuite destructor" << std::endl;
      teardown();
    }

    void LexerSuite::startup() {
      std::cout << "LexerSuite::startup()" << std::endl;
    }

    void LexerSuite::teardown() {
      std::cout << "LexerSuite::teardown()" << std::endl;
    }

    void LexerSuite::run() {
      std::cout << "LexerSuite::run()" << std::endl;
      // tests run from here
    }
  }
}
