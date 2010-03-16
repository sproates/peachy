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

// Entry point.
int main(int argc, char ** argv) {

  try {

    ScriptSource * scriptSource;

    if(argc < 2 || strcmp(argv[1], "-r") == 0 || strcmp(argv[1], "--repl") == 0) {
      // REPL mode
      Log::debug("REPL mode");
      scriptSource = new REPLScriptSource();
    } else {
      Log::debug(argv[1]);
      if(strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) {
        Log::debug("Displaying version info");
        print_intro(std::cout);
        return 0;
      } else if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        Log::debug("Displaying usage info");
        print_usage(argv[0], std::cout);
        return 0;
      } else if(argv[1][0] == '-') {
        Log::debug("Invalid option");
        print_invalid(argv[1], std::cout);
        print_usage(argv[0], std::cout);
        return 1;
      } else {
        // File mode
        Log::debug("File mode");
        scriptSource = new FileScriptSource(argv[argc - 1]);
      }
    }

    Environment * environment = new Environment();
    Script * script = new Script(scriptSource, environment);

    script->run();

    delete script;
    delete scriptSource;
    delete environment;

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
