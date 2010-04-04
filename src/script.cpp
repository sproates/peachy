#include "script.h"

#include <iostream>
#include <memory>

#include "environment.h"
#include "expression.h"
#include "expressionsource.h"
#include "log.h"
#include "parserexception.h"
#include "runtime.h"

namespace peachy {

  Script::Script(Log * logger, Environment * environment, Runtime * runtime,
		 ExpressionSource * expressionSource) {
    logger->debug("Script constructor");
    this->logger = logger;
    this->environment = environment;
    this->runtime = runtime;
    this->expressionSource = expressionSource;
  }

  Script::~Script() {
    logger->debug("Script destructor");
  }

  void Script::run() {
    logger->debug("Script::run()");

    try {
      std::auto_ptr<Expression> expression = expressionSource->nextExpression();
    } catch(ParserException & e) {
      logger->info("ParserException thrown");
      logger->info(e.what());
      return;
    }

    logger->debug("Reached end of script");
  }
}
