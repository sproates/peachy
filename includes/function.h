#ifndef PEACHY_FUNCTION_H
#define PEACHY_FUNCTION_H

namespace peachy {

  class Log;

  class Function {

    public:

      Function(Log * logger);
      virtual ~Function();

    protected:

      Log * logger;
  };
}

#endif
