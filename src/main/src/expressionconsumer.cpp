#include "expressionconsumer.h"

#include "log.h"

namespace peachy {

  ExpressionConsumer::ExpressionConsumer(Log * logger) {
    this->logger = logger;
  }

  ExpressionConsumer::~ExpressionConsumer() {}
}
