#include <fstream>
#include <stdexcept>
#include <string>

#include "filescriptsource.h"
#include "log.h"

namespace peachy {

  void FileScriptSource::construct(const char * filename) {
    Log::debug("FileScriptSource::construct()");
    stream = new std::ifstream(filename, std::ios_base::in);
    Log::debug("Ok, got stream");
    if(stream == NULL || !stream->good()) {
      Log::debug("Going to throw an exception now...");
      throw std::runtime_error(std::string("Can't open file for reading: ").append(filename));
    } else {
      Log::debug("Stream is good for IO");
    }
  }

  FileScriptSource::FileScriptSource(std::string filename) {
    Log::debug("FileScriptSource constructor");
    construct(filename.c_str());
  }

  FileScriptSource::FileScriptSource(const char * filename) {
    Log::debug("FileScriptSource constructor");
    construct(filename);
  }

  FileScriptSource::~FileScriptSource() {
    Log::debug("FileScriptSource destructor");
    stream->close();
    delete stream;
  }

  std::string FileScriptSource::getLine() {
    Log::debug("FileScriptSource::getLine()");
    std::getline(*stream, currentLine);
    return currentLine;
  }

  bool FileScriptSource::hasMoreLines() {
    Log::debug("FileScriptSource::hasMoreLines()");
    return !stream->eof();
  }
}
