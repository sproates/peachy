#include "assignmentexpression.h"

#include <string>

namespace peachy {

  AssignmentExpression::~AssignmentExpression() {
    logger->debug("AssignmentExpression destructor");
  }

  void AssignmentExpression::setLValue(std::string identifier) {
    lValue = identifier;
  }
}
