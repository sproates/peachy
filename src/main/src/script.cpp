#include "script.h"

#include <iostream>
#include <memory>
#include <stdexcept>

#include "environment.h"
#include "expressionconsumer.h"
#include "interpreterexception.h"
#include "lexerexception.h"
#include "log.h"
#include "parserexception.h"
#include "runtime.h"

namespace peachy {

  Script::Script(Log * logger, Environment * environment, Runtime * runtime,
		 ExpressionConsumer * expressionConsumer) {
    this->logger = logger;
    this->environment = environment;
    this->runtime = runtime;
    this->expressionConsumer = expressionConsumer;
  }

  Script::~Script() {}

  void Script::run() {
    try {
      expressionConsumer->consume();
    } catch(LexerException & le) {
      logger->info("LexerException thrown:");
      logger->info(le.what());
    } catch(ParserException & pe) {
      logger->info("ParserException thrown:");
      logger->info(pe.what());
      return;
    } catch(InterpreterException & ie) {
      logger->info("InterpreterException thrown:");
      logger->info(ie.what());
      return;
    } catch(std::runtime_error re) {
      logger->info("Runtime error thrown:");
      logger->info(re.what());
    } catch(...) {
      logger->debug("Something very bad happened");
      return;
    }
  }
}
