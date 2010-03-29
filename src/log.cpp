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

  void Log::enableDebug(bool debugEnabled) {
    this->debugEnabled = debugEnabled;
  }

  void Log::debug(const char * message) {
    if(debugEnabled) {
      *outputStream << "DEBUG: " << message << std::endl;
    }
  }

  void Log::debug(std::string message) {
    debug(message.c_str());
  }

  void Log::info(const char * message) {
    *outputStream << "INFO: " << message << std::endl;
  }

  void Log::info(std::string message) {
    info(message.c_str());
  }

  void Log::warning(const char * message) {
    *outputStream << "WARNING : " << message << std::endl;
  }

  void Log::warning(std::string message) {
    warning(message.c_str());
  }

  void Log::error(const char * message) {
    *outputStream << "ERROR : " << message << std::endl;
  }

  void Log::error(std::string message) {
    error(message.c_str());
  }

  void Log::fatal(const char * message) {
    *outputStream << "FATAL : " << message << std::endl;
  }

  void Log::fatal(std::string message) {
    fatal(message.c_str());
  }
}
