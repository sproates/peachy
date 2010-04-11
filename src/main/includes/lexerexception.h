#ifndef PEACHY_LEXEREXCEPTION_H
#define PEACHY_LEXEREXCEPTION_H

#include <stdexcept>
#include <string>

namespace peachy {

  class LexerException : public std::runtime_error {

    public:

      LexerException(const std::string& message) :
        std::runtime_error(message) {}

    private:

      LexerException();
      LexerException(const LexerException * lexerException);
      LexerException & operator = (const LexerException * lexerException);
  };
}

#endif

