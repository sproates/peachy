#ifndef PEACHY_PARSERSTATE_H
#define PEACHY_PARSERSTATE_H

namespace peachy {

  enum ParserState {
    PARSER_DEFAULT,
    PARSER_ERROR,
    PARSER_NEED_TOKEN
  };
}

#endif
