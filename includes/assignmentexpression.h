#ifndef PEACHY_ASSINGMENTEXPRESSION_H
#define PEACHY_ASSINGMENTEXPRESSION_H

#include "expression.h"
#include "expressiontype.h"
#include "log.h"

namespace peachy {

  class AssignmentExpression : public Expression {

    public:

      AssignmentExpression(Log * logger) : Expression(logger) {
        logger->debug("AssignmentExpression constructor");
        this->expressionType = EXPRESSION_ASSIGNMENT;
      }
      virtual ~AssignmentExpression();
  };
}

#endif
