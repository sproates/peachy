#ifndef PEACHY_INTERPRETER_H
#define PEACHY_INTERPRETER_H

namespace peachy {

  class ClassFactory;
  class Expression;
  class ExpressionSource;
  class Log;
  class Object;
  class Scope;
  class VariableExpression;

  class Interpreter {

    public:

      Interpreter(Log * logger, ExpressionSource * expressionSource,
        ClassFactory * classFactory);
      virtual ~Interpreter();
      void run();

    protected:

      Log * logger;
      ExpressionSource * expressionSource;
      ClassFactory * classFactory;

    private:

      Object * evaluate(Expression * expression, Scope * scope);
      void dumpVar(VariableExpression * v);
      void dumpObj(Object * o);
      Interpreter();
      Interpreter(const Interpreter & i);
      Interpreter & operator = (const Interpreter & i);
  };
}

#endif
