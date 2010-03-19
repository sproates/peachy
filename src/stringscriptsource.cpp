#include "stringscriptsource.h"

#include <ios>
#include <sstream>
#include <stdexcept>
#include <string>

#include "log.h"

namespace peachy {

  void StringScriptSource::construct(Log * logger, std::string scriptString) {
    this->logger = logger;
    logger->debug("StringScriptSource::construct()");
    stream = new std::istringstream(scriptString, std::ios_base::in);
    if(!stream->good()) {
      throw new std::runtime_error("Stream is no good for IO");
    } else {
      logger->debug("Stream is good for IO");
    }
  }

  StringScriptSource::StringScriptSource(Log * logger, std::string scriptString) {
    construct(logger, scriptString);
  }

  StringScriptSource::StringScriptSource(Log * logger, char * scriptString) {
    construct(logger, std::string(scriptString));
  }

  StringScriptSource::~StringScriptSource() {
    logger->debug("StringScriptSource destructor");
    delete stream;
  }

  std::string StringScriptSource::getLine() {
    logger->debug("StringScriptSource::getLine()");
    std::getline(*stream, currentLine);
    return currentLine;
  }

  bool StringScriptSource::hasMoreLines() {
    logger->debug("StringScriptSource::hasMoreLines()");
    return !stream->eof();
  }
}
