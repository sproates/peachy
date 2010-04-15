#include "intliteralexpression.h"

#include <sstream>

namespace peachy {

  IntLiteralExpression::~IntLiteralExpression() {}

  void IntLiteralExpression::setValue(int value) {
    this->value = value;
  }

  int IntLiteralExpression::getValue() {
    return value;
  }

  std::string IntLiteralExpression::toString() {
    std::ostringstream ss;
    ss << value;
    return ss.str();
  }
}
