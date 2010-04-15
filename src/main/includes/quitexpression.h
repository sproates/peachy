#ifndef PEACHY_QUITEXPRESSION_H
#define PEACHY_QUITEXPRESSION_H

#include <string>

#include "expression.h"
#include "expressiontype.h"
#include "log.h"

namespace peachy {

  class QuitExpression : public Expression {

    public:

      QuitExpression(Log * logger) : Expression(logger) {
        this->expressionType = EXPRESSION_QUIT;
      }
      ~QuitExpression();
      std::string toString();
  };
}

#endif
