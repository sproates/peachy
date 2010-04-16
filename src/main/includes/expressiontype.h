#ifndef PEACHY_EXPRESSIONTYPE_H
#define PEACHY_EXPRESSIONTYPE_H

namespace peachy {

  enum ExpressionType {
    EXPRESSION_ADDITION,
    EXPRESSION_ASSIGNMENT,
    EXPRESSION_BOOLEAN_LITERAL,
    EXPRESSION_INT_LITERAL,
    EXPRESSION_QUIT,
    EXPRESSION_STRING_LITERAL,
    EXPRESSION_UNKNOWN,
    EXPRESSION_VALUE,
    EXPRESSION_VARIABLE
  };
}

#endif
