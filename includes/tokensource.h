#ifndef PEACHY_TOKENSOURCE_H
#define PEACHY_TOKENSOURCE_H

#include <memory>

namespace peachy {

  class Log;
  class ScriptSource;
  class Token;

  class TokenSource {

    public:

      TokenSource(Log * logger, ScriptSource * scriptSource);
      virtual ~TokenSource();

      virtual std::auto_ptr<Token> nextToken() = 0;

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
