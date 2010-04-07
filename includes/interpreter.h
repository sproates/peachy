#ifndef PEACHY_INTERPRETER_H
#define PEACHY_INTERPRETER_H

namespace peachy {

  class Expression;
  class ExpressionSource;
  class Log;
  class Object;

  class Interpreter {

    public:

      Interpreter(Log * logger, ExpressionSource * expressionSource);
      virtual ~Interpreter();
      void run();

    protected:

      Log * logger;
      ExpressionSource * expressionSource;

    private:

      Object * evaluate(Expression * expression);
      Interpreter();
      Interpreter(const Interpreter & i);
      Interpreter & operator = (const Interpreter & i);
  };
}

#endif
