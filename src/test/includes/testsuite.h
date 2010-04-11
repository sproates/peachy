#ifndef PEACHY_TEST_TESTSUITE_H
#define PEACHY_TEST_TESTSUITE_H

namespace peachy {

  namespace test {

    class TestSuite {

      public:

        TestSuite();
        virtual ~TestSuite();
        virtual void startup() = 0;
        virtual void teardown() = 0;
        virtual void run() = 0;
    };
  }
}

#endif
