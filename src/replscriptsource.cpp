#include "replscriptsource.h"

#include <iostream>
#include <string>

#include "log.h"

namespace peachy {

  REPLScriptSource::REPLScriptSource(Log * logger) {
    this->logger = logger;
    logger->debug("REPLScriptSource constructor");
    stream = &std::cin;
  }

  REPLScriptSource::~REPLScriptSource() {
    logger->debug("REPLScriptSource destructor");
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

