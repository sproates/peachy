#include <csignal>
#include <cstring>
#include <exception>
#include <iostream>
#include <stdexcept>

#include "classfactory.h"
#include "environment.h"
#include "expressionfactory.h"
#include "expressionsource.h"
#include "filescriptsource.h"
#include "interpreter.h"
#include "lexer.h"
#include "log.h"
#include "nullostream.h"
#include "peachy.h"
#include "parser.h"
#include "replscriptsource.h"
#include "runtime.h"
#include "script.h"
#include "scriptsource.h"
#include "stringscriptsource.h"
#include "tokenfactory.h"
#include "tokensource.h"

using namespace peachy;

ScriptSource * handle_args(Log * logger, const int argc, const char ** argv);

// Entry point.
int main(const int argc, const char ** argv) {

  Log * logger = new Log(&(std::cout));
  NullOStream * ostream = new NullOStream();
  Log * nullLogger = new Log(ostream);
  int returnCode = 0;

  try {

    ScriptSource * scriptSource = handle_args(nullLogger, argc, argv);
    Environment * environment = new Environment(nullLogger);
    Runtime * runtime = new Runtime(nullLogger);
    TokenFactory * tokenFactory = new TokenFactory(nullLogger, nullLogger);
    TokenSource * tokenSource = new Lexer(nullLogger, tokenFactory, scriptSource);
    ExpressionFactory * expressionFactory = new ExpressionFactory(nullLogger,
      nullLogger);
    ExpressionSource * expressionSource = new Parser(logger,
      expressionFactory, tokenSource);
    ClassFactory * classFactory = new ClassFactory(nullLogger, logger);
    Interpreter * interpreter = new Interpreter(logger, expressionSource,
      classFactory);
    Script * script = new Script(logger, environment, runtime, interpreter);

    script->run();

    delete script;
    delete interpreter;
    delete expressionSource;
    delete expressionFactory;
    delete tokenSource;
    delete tokenFactory;
    delete runtime;
    delete environment;
    delete scriptSource;

  } catch (std::runtime_error & re) {
    logger->debug("runtime error caught");
    print_exception(re, std::cerr);
    returnCode = 1;
  } catch (std::exception & e) {
    logger->debug("exception caught");
    print_exception(e, std::cerr);
    returnCode = 1;
  } catch(...) {
    logger->debug("something else caught");
    print_fatal("Unknown fatal error", std::cerr);
    returnCode = 1;
  }

  return returnCode;
}

ScriptSource * handle_args(Log * logger, const int argc, const char ** argv) {

  if(argc < 2 || strcmp(argv[1], "-r") == 0 || strcmp(argv[1], "--repl") == 0) {
    // REPL mode
    logger->debug("REPL mode");
    return new REPLScriptSource(logger);
  } else {
    logger->debug(argv[1]);
    if(strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) {
      logger->debug("Displaying version info");
      print_intro(std::cout);
      exit(0);
    } else if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
      logger->debug("Displaying usage info");
      print_usage(argv[0], std::cout);
      exit(0);
    } else if(argv[1][0] == '-') {
      logger->debug("Invalid option");
      print_invalid(argv[1], std::cout);
      print_usage(argv[0], std::cout);
      exit(1);
    } else {
      // File mode
      logger->debug("File mode");
      return new FileScriptSource(logger, argv[argc - 1]);
    }
  }
}
