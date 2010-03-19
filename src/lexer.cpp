#include "lexer.h"

#include "log.h"

namespace peachy {

  Lexer::Lexer(Log * logger) {
    this->logger = logger;
    logger->debug("Lexer constructor");
  }

  Lexer::~Lexer() {
    logger->debug("Lexer destructor");
  }
}

