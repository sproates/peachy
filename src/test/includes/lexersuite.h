#ifndef PEACHY_TEST_LEXERSUITE_H
#define PEACHY_TEST_LEXERSUITE_H

#include <iostream>

#include "testsuite.h"

namespace peachy {

  namespace test {

    class LexerSuite : public TestSuite {

      public:

        LexerSuite() : TestSuite() {
          std::cout << "LexerSuite constructor" << std::endl;
          startup();
        }

        ~LexerSuite();

        void startup();
        void teardown();
        void run();
    };
  }
}

#endif
