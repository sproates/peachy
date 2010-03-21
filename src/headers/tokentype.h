#ifndef PEACHY_TOKENTYPE_H
#define PEACHY_TOKENTYPE_H

namespace peachy {

  enum TokenType {

    TOKEN_EMPTY,
    TOKEN_EOF,
    TOKEN_IDENTIFIER,
    TOKEN_INTEGER,
    TOKEN_KEYWORD,
    TOKEN_NEWLINE,
    TOKEN_OPERATOR,
    TOKEN_STRING
  };
}

#endif

