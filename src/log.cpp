#include <iostream>
#include <string>

#include "log.h"

namespace peachy {

  void Log::debug(const char *message) {
#ifdef LOG_DEBUG_ENABLED
    std::cout << "DEBUG: " << message << std::endl;
#endif
  }

  void Log::debug(std::string message) {
#ifdef LOG_DEBUG_ENABLED
    std::cout << "DEBUG: " << message << std::endl;
#endif
  }
}
