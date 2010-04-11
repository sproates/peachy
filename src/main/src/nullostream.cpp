#include "nullostream.h"

#include <string>

namespace peachy {

  NullOStream & operator << (NullOStream & nullOStream, const std::string & string) {
    (void) string;
    return nullOStream;
  }

  NullOStream & operator << (NullOStream & nullOStream, const char * string) {
    (void) string;
    return nullOStream;
  }
}
