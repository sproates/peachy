#ifndef PEACHY_NULLOSTREAM_H
#define PEACHY_NULLOSTREAM_H

#include <ostream>

namespace peachy {

  class NullOStream : public std::ostream {

    public:

      NullOStream() : std::ostream(NULL) {}
      virtual ~NullOStream() {}
  };
}

#endif
