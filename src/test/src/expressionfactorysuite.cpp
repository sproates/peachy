#include "expressionfactorysuite.h"

#include <string>

#include "expression.h"
#include "expressionfactory.h"
#include "log.h"
#include "nullostream.h"
#include "testsuite.h"

namespace peachy {

  namespace test {

    ExpressionFactorySuite::~ExpressionFactorySuite() {
      teardown();
    }

    void ExpressionFactorySuite::startup() {
      ostream = new NullOStream();
      logger = new Log(ostream);
      expressionFactory = new ExpressionFactory(logger, logger);
    }

    void ExpressionFactorySuite::teardown() {
      delete expression;
      delete expressionFactory;
      delete logger;
      delete ostream;
    }

    void ExpressionFactorySuite::run() {

    }
  }
}
