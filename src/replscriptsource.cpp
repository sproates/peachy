#include "replscriptsource.h"

#include <iostream>
#include <string>

#include "log.h"

namespace peachy {

  REPLScriptSource::REPLScriptSource() {
    Log::debug("REPLScriptSource constructor");
    stream = &std::cin;
  }

  REPLScriptSource::~REPLScriptSource() {
    Log::debug("REPLScriptSource destructor");
    delete stream;
  }

  std::string REPLScriptSource::getLine() {
    std::getline(*stream, currentLine);
    return currentLine;
  }

  bool REPLScriptSource::hasMoreLines() {
    return true;
  }  
}
