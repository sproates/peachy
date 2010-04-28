#include "expressionconsumer.h"

#include "log.h"

namespace peachy {

  ExpressionConsumer::ExpressionConsumer(Log * logger) {
    logger->debug("ExpressionConsumer constructor");
    this->logger = logger;
  }

  ExpressionConsumer::~ExpressionConsumer() {
    logger->debug("ExpressionConsumer destructor");
  }
}
