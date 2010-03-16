#include "stringscriptsource.h"

#include <ios>
#include <sstream>
#include <stdexcept>
#include <string>

#include "log.h"

namespace peachy {

  void StringScriptSource::construct(std::string scriptString) {
    Log::debug("StringScriptSource::construct()");
    stream = new std::istringstream(scriptString, std::ios_base::in);
    if(!stream->good()) {
      throw new std::runtime_error("Stream is no good for IO");
    } else {
      Log::debug("Stream is good for IO");
    }
  }

  StringScriptSource::StringScriptSource(std::string scriptString) {
    Log::debug("StringScriptSource constructor");
    construct(scriptString);
  }

  StringScriptSource::StringScriptSource(char * scriptString) {
    Log::debug("StringScriptSource constructor");
    construct(std::string(scriptString));
  }

  StringScriptSource::~StringScriptSource() {
    Log::debug("StringScriptSource destructor");
    delete stream;
  }

  std::string StringScriptSource::getLine() {
    Log::debug("StringScriptSource::getLine()");
    std::getline(*stream, currentLine);
    return currentLine;
  }

  bool StringScriptSource::hasMoreLines() {
    Log::debug("StringScriptSource::hasMoreLines()");
    return !stream->eof();
  }
}
