#include "log.h"

#include <ostream>
#include <string>

namespace peachy {

  Log::Log(std::ostream * outputStream) {
    this->outputStream = outputStream;
    debugEnabled = true;
    infoEnabled = true;
    warningEnabled = true;
    errorEnabled = true;
    fatalEnabled = true;
  }

  void Log::enableDebug(bool b) {
    debugEnabled = b;
  }

  void Log::enableInfo(bool b) {
    infoEnabled = b;
  }

  void Log::enableWarning(bool b) {
    warningEnabled = b;
  }

  void Log::enableError(bool b) {
    errorEnabled = b;
  }

  void Log::enableFatal(bool b) {
    fatalEnabled = b;
  }

  void Log::debug(const char * message) {
    if(debugEnabled) {
      *outputStream << "DEBUG: " << message << std::endl;
    }
  }

  void Log::debug(std::string message) {
    if(debugEnabled) {
      debug(message.c_str());
    }
  }

  void Log::info(const char * message) {
    if(infoEnabled) {
      *outputStream << "INFO: " << message << std::endl;
    }
  }

  void Log::info(std::string message) {
    if(infoEnabled) {
      info(message.c_str());
    }
  }

  void Log::warning(const char * message) {
    if(warningEnabled) {
      *outputStream << "WARNING : " << message << std::endl;
    }
  }

  void Log::warning(std::string message) {
    if(warningEnabled) {
      warning(message.c_str());
    }
  }

  void Log::error(const char * message) {
    if(errorEnabled) {
      *outputStream << "ERROR : " << message << std::endl;
    }
  }

  void Log::error(std::string message) {
    if(errorEnabled) {
      error(message.c_str());
    }
  }

  void Log::fatal(const char * message) {
    if(fatalEnabled) {
      *outputStream << "FATAL : " << message << std::endl;
    }
  }

  void Log::fatal(std::string message) {
    if(fatalEnabled) {
      fatal(message.c_str());
    }
  }
}
