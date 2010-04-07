#ifndef PEACHY_FUNCTION_H
#define PEACHY_FUNCTION_H

#include <deque>
#include <string>

namespace peachy {

  class Expression;
  class Log;

  class Function {

    public:

      Function(Log * logger, std::string name,
        std::deque<Expression*> expressions);
      virtual ~Function();
      std::string getName();
      std::deque<Expression*> getExpressions();

    protected:

      Log * logger;
      std::string name;
      std::deque<Expression*> expressions;
  };
}

#endif
