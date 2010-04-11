#ifndef PEACHY_RUNTIME_H
#define PEACHY_RUNTIME_H

namespace peachy {

  class Log;

  class Runtime {

    public:

      Runtime(Log * logger);
      ~Runtime();

    private:

      Log * logger;
      Runtime(const Runtime & runtime);
      Runtime & operator = (const Runtime & runtime);
  };
}

#endif
