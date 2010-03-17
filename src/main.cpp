#include <csignal>
#include <cstring>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

#include "environment.h"
#include "filescriptsource.h"
#include "log.h"
#include "peachy.h"
#include "replscriptsource.h"
#include "script.h"
#include "scriptsource.h"
#include "stringscriptsource.h"

using namespace peachy;

ScriptSource * handle_args(const int argc, const char ** argv);
void handle_interrupt(int param);

// Entry point.
int main(const int argc, const char ** argv) {

  try {

    signal(SIGINT, handle_interrupt);

    ScriptSource * scriptSource = handle_args(argc, argv);
    Environment * environment = new Environment();
    Script * script = new Script(scriptSource, environment);

    script->run();

    delete script;
    delete environment;
    delete scriptSource;

  } catch (std::runtime_error & re) {
    Log::debug("runtime error caught");
    print_exception(re, std::cerr);
    return 1;
  } catch (std::exception & e) {
    Log::debug("exception caught");
    print_exception(e, std::cerr);
    return 1;
  } catch(...) {
    Log::debug("something else caught");
    print_fatal(std::string("Unknown fatal error"), std::cerr);
    return 1;
  }

  return 0;
}

ScriptSource * handle_args(const int argc, const char ** argv) {

  if(argc < 2 || strcmp(argv[1], "-r") == 0 || strcmp(argv[1], "--repl") == 0) {
    // REPL mode
    Log::debug("REPL mode");
    return new REPLScriptSource();
  } else {
    Log::debug(argv[1]);
    if(strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) {
      Log::debug("Displaying version info");
      print_intro(std::cout);
      exit(0);
    } else if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
      Log::debug("Displaying usage info");
      print_usage(argv[0], std::cout);
      exit(0);
    } else if(argv[1][0] == '-') {
      Log::debug("Invalid option");
      print_invalid(argv[1], std::cout);
      print_usage(argv[0], std::cout);
      exit(1);
    } else {
      // File mode
      Log::debug("File mode");
      return new FileScriptSource(argv[argc - 1]);
    }
  }
}

void handle_interrupt(int param) {

  Log::debug("CTRL-C caught");
  print_interrupted(std::cout);
  exit(0);
}
