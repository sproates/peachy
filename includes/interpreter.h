#ifndef PEACHY_INTERPRETER_H
#define PEACHY_INTERPRETER_H

namespace peachy {

  class ExpressionSource;
  class Log;

  class Interpreter {

    public:

      Interpreter(Log * logger, ExpressionSource * expressionSource);
      virtual ~Interpreter();

    protected:

      Log * logger;
      ExpressionSource * expressionSource;

    private:

      Interpreter();
      Interpreter(const Interpreter & i);
      Interpreter & operator = (const Interpreter & i);
  };
}

#endif
