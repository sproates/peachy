#ifndef PEACHY_EXPRESSIONCONSUMER_H
#define PEACHY_EXPRESSIONCONSUMER_H

namespace peachy {

  class Log;

  class ExpressionConsumer {

    public:

      ExpressionConsumer(Log * logger);
      virtual ~ExpressionConsumer();
      virtual void consume() = 0;

    protected:

      Log * logger;

    private:

      ExpressionConsumer();
      ExpressionConsumer(const ExpressionConsumer & e);
      ExpressionConsumer & operator = (const ExpressionConsumer & e);
  };
}

#endif
