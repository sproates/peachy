#include "quitexpression.h"

#include <string>

namespace peachy {

  QuitExpression::~QuitExpression() {}

  std::string QuitExpression::toString() {
    return std::string("[QUIT]");
  }
}
