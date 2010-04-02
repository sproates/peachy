#ifndef PEACHY_EXPRESSION_H
#define PEACHY_EXPRESSION_H

namespace peachy {

  class Log;

  class Expression {

    public:

      Expression(Log * logger);
      virtual ~Expression();

    protected:

      Log * logger;

    private:

      Expression();
      Expression(const Expression & expression);
      Expression & operator = (const Expression & expression);
  };
}

#endif
