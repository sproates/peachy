#ifndef PEACHY_PARSEREXCEPTION_H
#define PEACHY_PARSEREXCEPTION_H

#include <stdexcept>
#include <string>

namespace peachy {

  class ParserException : public std::runtime_error {

    public:

      ParserException(const std::string& message) :
        std::runtime_error(message) {}

    private:

      ParserException();
      ParserException(const ParserException * parserException);
      ParserException & operator = (const ParserException * parserException);
  };
}

#endif

