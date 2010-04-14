#include "filescriptsource.h"

#include "log.h"
#include "nullostream.h"
#include "testsuite.h"

namespace peachy {

  namespace test {

    class FileScriptSourceSuite : public TestSuite {

      public:

        FileScriptSourceSuite() : TestSuite() {
          startup();
        }

        ~FileScriptSourceSuite();

      private:

        void startup();
        void teardown();
        void run();

        Log * logger;
        FileScriptSource * fileScriptSource;
        NullOStream * ostream;
    };
  }
}
