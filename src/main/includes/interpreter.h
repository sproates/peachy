#ifndef PEACHY_INTERPRETER_H
#define PEACHY_INTERPRETER_H

#include "expressionconsumer.h"
#include "log.h"

namespace peachy {

  class ClassFactory;
  class Expression;
  class ExpressionSource;
  class Object;
  class Scope;
  class VariableExpression;

  class Interpreter : public ExpressionConsumer {

    public:

      Interpreter(Log * logger, ExpressionSource * expressionSource,
        ClassFactory * classFactory) : ExpressionConsumer(logger) {
        logger->debug("Interpreter constructor");
        this->expressionSource = expressionSource;
        this->classFactory = classFactory;
        logger->debug("constructed");
      }

      virtual ~Interpreter();
      void consume();

    protected:

      ExpressionSource * expressionSource;
      ClassFactory * classFactory;

    private:

      Expression * evaluate(Expression * expression, Scope * scope);
      Expression * evaluateIntLiteral(Expression * expression);
      Expression * evaluateStringLiteral(Expression * expression);
      Expression * evaluateVariable(Expression * expression, Scope * scope);
      Expression * evaluateAddition(Expression * expression, Scope * scope);
      Expression * evaluateIntLiteralAddition(Expression * lValue,
        Expression * rValue, Scope * scope);
      Expression * evaluateStringLiteralAddition(Expression * lValue,
        Expression * rValue, Scope * scope);
      Expression * evaluateVariableAddition(Expression * lValue,
        Expression * rValue, Scope * scope);
      Expression * assignValueToVariable(Expression * lValue,
        Expression * rValue, Scope * scope);
      Expression * assignVariableToVariable(Expression * lValue,
        Expression * rValue, Scope * scope);
      void dumpVar(VariableExpression * v);
      void dumpObj(Object * o);
      Interpreter();
      Interpreter(const Interpreter & i);
      Interpreter & operator = (const Interpreter & i);
  };
}

#endif
