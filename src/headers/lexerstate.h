#ifndef PEACHY_LEXERSTATE_H
#define PEACHY_LEXERSTATE_H

namespace peachy {

  enum LexerState {

    LEXER_COMPLETE,
    LEXER_DEFAULT,
    LEXER_ERROR,
    LEXER_NEED_INPUT
  };
}

#endif
