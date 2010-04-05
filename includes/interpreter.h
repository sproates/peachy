#ifndef PEACHY_INTERPRETER_H
#define PEACHY_INTERPRETER_H

namespace peachy {

  class Log;

  class Interpreter {

    public:

      Interpreter(Log * logger);
      virtual ~Interpreter();

    protected:

      Log * logger;

    private:

      Interpreter();
      Interpreter(const Interpreter & i);
      Interpreter & operator = (const Interpreter & i);
  };
}

#endif
