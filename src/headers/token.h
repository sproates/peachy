#ifndef PEACHY_TOKEN_H
#define PEACHY_TOKEN_H

namespace peachy {

  class Log;

  class Token {

    public:

      Token(Log * logger);
      ~Token();

    private:

      Log * logger;

      Token();
      Token(const Token & token);
      Token & operator = (const Token & token);
  };
}

#endif

