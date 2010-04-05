#include <fstream>
#include <stdexcept>
#include <string>

#include "filescriptsource.h"
#include "log.h"

namespace peachy {

  void FileScriptSource::construct(Log * logger, const char * filename) {
    logger->debug("FileScriptSource::construct()");
    this->logger = logger;
    stream = new std::ifstream(filename, std::ios_base::in);
    logger->debug("Ok, got stream");
    if(stream == NULL || !stream->good()) {
      logger->debug("Going to throw an exception now...");
      throw std::runtime_error(std::string("Can't open file for reading: ").append(filename));
    } else {
      logger->debug("Stream is good for IO");
    }
  }

  FileScriptSource::FileScriptSource(Log * logger, std::string filename) {
    logger->debug("FileScriptSource constructor");
    construct(logger, filename.c_str());
  }

  FileScriptSource::FileScriptSource(Log * logger, const char * filename) {
    logger->debug("FileScriptSource constructor");
    construct(logger, filename);
  }

  FileScriptSource::~FileScriptSource() {
    logger->debug("FileScriptSource destructor");
  }
}
