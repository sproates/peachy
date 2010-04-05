#ifndef PEACHY_ASSINGMENTEXPRESSION_H
#define PEACHY_ASSINGMENTEXPRESSION_H

#include <string>

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

      void setLValue(std::string identifier);

    private:

      std::string lValue;
  };
}

#endif
