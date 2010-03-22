#ifndef PEACHY_TOKENSOURCE_H
#define PEACHY_TOKENSOURCE_H

namespace peachy {

  class Log;
  class Token;

  class TokenSource {

    public:

      TokenSource(Log * logger);
      virtual ~TokenSource();

      virtual Token * nextToken() = 0;

    protected:

      Log * logger;

    private:

      TokenSource();
      TokenSource(const TokenSource & tokenSource);
      TokenSource & operator = (const TokenSource & tokenSource);
  };
}

#endif

