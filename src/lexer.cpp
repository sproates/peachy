#include "lexer.h"

#include "log.h"

namespace peachy {

  Lexer::~Lexer() {
    logger->debug("Lexer destructor");
  }
}

