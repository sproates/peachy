#ifndef PEACHY_INTERPRETEREXCEPTION_H
#define PEACHY_INTERPRETEREXCEPTION_H

#include <stdexcept>
#include <string>

namespace peachy {

  class InterpreterException : public std::runtime_error {

    public:

      InterpreterException(const std::string& message) :
        std::runtime_error(message) {}

    private:

      InterpreterException();
      InterpreterException(const InterpreterException * e);
      InterpreterException & operator = (const InterpreterException * e);
  };
}

#endif

