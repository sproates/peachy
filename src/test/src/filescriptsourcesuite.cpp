#include "filescriptsourcesuite.h"

#include <stdexcept>
#include <string>

#include "filescriptsource.h"
#include "log.h"
#include "nullostream.h"
#include "testsuite.h"

namespace peachy {

  namespace test {

    FileScriptSourceSuite::~FileScriptSourceSuite() {
      teardown();
    }

    void FileScriptSourceSuite::startup() {
      ostream = new NullOStream();
      logger = new Log(ostream);
    }

    void FileScriptSourceSuite::teardown() {
      delete fileScriptSource;
      delete logger;
      delete ostream;
    }

    void FileScriptSourceSuite::run() {
      ASSERT_THROWS(new FileScriptSource(logger, "nonexistantfile.peachy"), std::runtime_error, "Throws runtime_error on invalid file");
      ASSERT_THROWS(new FileScriptSource(logger, std::string("nonexistantfile.peachy")), std::runtime_error, "Throws runtime_error on invalid file");
    }
  }
}
