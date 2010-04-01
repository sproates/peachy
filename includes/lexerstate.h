#ifndef PEACHY_LEXERSTATE_H
#define PEACHY_LEXERSTATE_H

namespace peachy {

  enum LexerState {

    LEXER_COMPLETE,
    LEXER_DEFAULT,
    LEXER_ERROR,
    LEXER_IN_COMMENT_LINE,
    LEXER_IN_IDENTIFIER,
    LEXER_IN_NUMBER,
    LEXER_IN_OPERATOR,
    LEXER_IN_STRING,
    LEXER_NEED_INPUT
  };
}

#endif
