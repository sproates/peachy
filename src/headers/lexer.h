#ifndef PEACHY_LEXER_H
#define PEACHY_LEXER_H

namespace peachy {

  class Lexer {

    public:

      Lexer();
      ~Lexer();

    private:

      // No copy allowed.
      Lexer(const Lexer & lexer);

      // No assignment allowed.
      Lexer & operator = (const Lexer & lexer);
  };
}

#endif

