#include "istreamscriptsource.h"

#include <istream>
#include <string>

#include "log.h"

namespace peachy {

  IStreamScriptSource::IStreamScriptSource(Log * logger,
    std::istream * stream) {
    logger->debug("IStreamScriptSource constructor");
    this->logger = logger;
    this->stream = stream;
  }

  IStreamScriptSource::~IStreamScriptSource() {
    logger->debug("IStreamScriptSource destructor");
    delete stream;
  }

  std::string IStreamScriptSource::getLine() {
    logger->debug("IStreamScriptSource::getLine()");
    std::getline(*stream, currentLine);
    return currentLine;
  }

  bool IStreamScriptSource::hasMoreLines() {
    logger->debug("IStreamScriptSource::hasMoreLines()");
    return !stream->eof();
  }
}
