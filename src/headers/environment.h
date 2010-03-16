#ifndef PEACHY_ENVIRONMENT_H
#define PEACHY_ENVIRONMENT_H

namespace peachy {

  class Environment {

    public:
      Environment();
      ~Environment();
      Environment(const Environment& environment);
      Environment& operator = (const Environment& environment);
  };
}

#endif
