#ifndef PEACHY_ENVIRONMENT_H
#define PEACHY_ENVIRONMENT_H

namespace peachy {

  class Log;

  class Environment {

    public:

      Environment(Log * logger);
      ~Environment();

    private:

      Log * logger;
      Environment(const Environment & environment);
      Environment & operator = (const Environment & environment);
  };
}

#endif
