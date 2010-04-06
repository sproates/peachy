#ifndef PEACHY_SCOPE_H
#define PEACHY_SCOPE_H

namespace peachy {

  class Log;

  class Scope {

    public:

      Scope(Log * logger);
      virtual ~Scope();

    protected:

      Log * logger;

    private:

      Scope();
      Scope(const Scope & s);
      Scope & operator = (const Scope & s);
  };
}

#endif
