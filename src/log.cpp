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
    *outputStream << "DEBUG: " << message << std::endl;
#endif
  }

  void Log::info(const char * message) {
#ifdef LOG_INFO_ENABLED
    *outputStream << "INFO: " << message << std::endl;
#endif
  }

  void Log::info(std::string message) {
#ifdef LOG_INFO_ENABLED
    *outputStream << "INFO : " << message << std::endl;
#endif
  }
}

