#ifndef PEACHY_TEST_TESTSUITE_H
#define PEACHY_TEST_TESTSUITE_H

#include <iostream>

#define ASSERT_THROWS(expression, exceptionType, message) {   \
  bool thrown = false;                                        \
  try {                                                       \
    (expression);                                             \
  } catch(exceptionType&) {                                   \
    thrown = true;                                            \
  }                                                           \
  __assertThrows(thrown, message, __FILE__, __LINE__);        \
}

#define ASSERT_EQUALS(expression, message) {                  \
  __assertEquals(expression, message, __FILE__, __LINE__);    \
}

#define ASSERT_INSTANCE(expression, expectedType, message) {  \
  __assertInstance(expression, expectedType, message,         \
    __FILE__, __LINE__);                                      \
}

namespace peachy {

  namespace test {

    class TestSuite {

      public:

        TestSuite();
        virtual ~TestSuite();
        virtual void startup() = 0;
        virtual void teardown() = 0;
        virtual void run() = 0;
        int getTestCount();
        int getFailCount();
        int getPassCount();

      protected:

        int testCount;
        int failCount;
        int passCount;

        void __assertThrows(bool thrown, const char * message,
          const char * file, int line);
        void __assertEquals(bool condition, const char * message,
          const char * file, int line);
        template <class T, class U>
        inline void __assertInstance(T expression, U expectedType,
          const char * message, const char * file, int line) {
          (void) expectedType;
          testCount++;
          U u = dynamic_cast<U>(expression);
          if(u != NULL) {
            passCount++;
          } else {
            failCount++;
            std::cout << "FAIL: " << message << std::endl;
            std::cout << "In " << file << " at line " << line << std::endl;
          }
        }
    };
  }
}

#endif
