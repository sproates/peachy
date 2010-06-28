#ifndef PEACHY_PARSERSTATE_H
#define PEACHY_PARSERSTATE_H

namespace peachy {

  enum ParserState {
    PARSER_ASSIGNMENT,
    PARSER_DEFAULT,
    PARSER_ERROR,
    PARSER_IN_CONDITION,
    PARSER_NEED_TOKEN
  };
}

#endif
