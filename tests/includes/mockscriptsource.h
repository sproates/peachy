#ifndef PEACHY_TEST_MOCKSCRIPTSOURCE_H
#define PEACHY_TEST_MOCKSCRIPTSOURCE_H

#include "scriptsource.h"

namespace peachy {

  class Log;

  namespace test {

    class MockScriptSource : public ScriptSource {

      public:

        MockScriptSource(Log * logger);
        virtual ~MockScriptSource();
	std::string getLine();
	bool hasMoreLines();

      protected:

        Log * logger;

      private:

        MockScriptSource();
        MockScriptSource(const MockScriptSource & mockScriptSource);
        MockScriptSource & operator =
          (const MockScriptSource & mockScriptSource);
    };
  }
}

#endif

