#include "log.h"

#include <ostream>
#include <string>

namespace peachy {

  Log::Log(std::ostream * outputStream) {
    this->outputStream = outputStream;
  }

  void Log::debug(const char * message) {
#ifdef LOG_DEBUG_ENABLED
    *outputStream << "DEBUG: " << message << std::endl;
#endif
  }

  void Log::debug(std::string message) {
#ifdef LOG_DEBUG_ENABLED
    debug(message.c_str());
#endif
  }

  void Log::info(const char * message) {
#ifdef LOG_INFO_ENABLED
    *outputStream << "INFO: " << message << std::endl;
#endif
  }

  void Log::info(std::string message) {
#ifdef LOG_INFO_ENABLED
    info(message.c_str());
#endif
  }

  void Log::warning(const char * message) {
#ifdef LOG_WARNING_ENABLED
    *outputStream << "WARNING : " << message << std::endl;
#endif
  }

  void Log::warning(std::string message) {
#ifdef LOG_WARNING_ENABLED
    warning(message.c_str());
#endif
  }

  void Log::error(const char * message) {
#ifdef LOG_ERROR_ENABLED
    *outputStream << "ERROR : " << message << std::endl;
#endif
  }

  void Log::error(std::string message) {
#ifdef LOG_ERROR_ENABLED
    error(message.c_str());
#endif
  }

  void Log::fatal(const char * message) {
#ifdef LOG_FATAL_ENABLED
    *outputStream << "FATAL : " << message << std::endl;
#endif
  }

  void Log::fatal(std::string message) {
#ifdef LOG_FATAL_ENABLED
    fatal(message.c_str());
#endif
  }
}

