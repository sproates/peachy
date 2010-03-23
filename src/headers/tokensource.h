#ifndef PEACHY_TOKENSOURCE_H
#define PEACHY_TOKENSOURCE_H

namespace peachy {

  class Log;
  class ScriptSource;
  class Token;

  class TokenSource {

    public:

      TokenSource(Log * logger, ScriptSource * scriptSource);
      virtual ~TokenSource();

      virtual Token * nextToken() = 0;

    protected:

      Log * logger;
      ScriptSource * scriptSource;

    private:

      TokenSource();
      TokenSource(const TokenSource & tokenSource);
      TokenSource & operator = (const TokenSource & tokenSource);
  };
}

#endif

