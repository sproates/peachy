#ifndef PEACHY_TEST_LEXERSUITE_H
#define PEACHY_TEST_LEXERSUITE_H

#include "lexer.h"
#include "log.h"
#include "nullostream.h"
#include "scriptsource.h"
#include "testsuite.h"
#include "token.h"
#include "tokenfactory.h"

namespace peachy {

  namespace test {

    class LexerSuite : public TestSuite {

      public:

        LexerSuite() : TestSuite() {
          startup();
        }

        ~LexerSuite();

      private:

        void startup();
        void teardown();
        void run();

        Lexer * lexer;
        Log * logger;
        NullOStream * ostream;
        ScriptSource * scriptSource;
        Token * token;
        TokenFactory * tokenFactory;
    };
  }
}

#endif
