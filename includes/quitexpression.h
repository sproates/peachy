#ifndef PEACHY_QUITEXPRESSION_H
#define PEACHY_QUITEXPRESSION_H

#include "expression.h"
#include "log.h"

namespace peachy {

  class QuitExpression : public Expression {

    public:

      QuitExpression(Log * logger) : Expression(logger) {
        logger->debug("QuitExpression constructor");
      }
      ~QuitExpression();
  };
}

#endif
