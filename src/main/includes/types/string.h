#ifndef PEACHY_STRING_H
#define PEACHY_STRING_H

#include <string>

#include "class.h"
#include "classfactory.h"
#include "log.h"
#include "object.h"

namespace peachy {

  class String : public Object {

    public:

      String(Log * logger, ClassFactory * classFactory, std::string value) :
      Object(logger, classFactory) {
        logger->debug("String constructor");
        this->clazz = classFactory->getClass(std::string("String"));
        this->value = value;
        this->logger = logger;
      }
      virtual ~String();
      std::string getValue();
      Object * add(Object * o);
      Object * clone();

    protected:

      Log * logger;
      std::string value;

    private:

      String();
      String(const String & s);
      String & operator = (const String & s);
  };
}

#endif
