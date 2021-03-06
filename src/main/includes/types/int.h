#ifndef PEACHY_INT_H
#define PEACHY_INT_H

#include <string>

#include "class.h"
#include "classfactory.h"
#include "log.h"
#include "object.h"

namespace peachy {

  class Int : public Object {

    public:

      Int(Log * logger, ClassFactory * classFactory, int value) :
      Object(logger, classFactory) {
        this->clazz = classFactory->getClass(std::string("Int"));
        this->value = value;
        this->logger = logger;
      }
      virtual ~Int();
      int getValue();
      void setValue(int value);
      Object * add(Object * o);
      Object * clone();
      std::string toString();

    protected:

      Log * logger;
      int value;

    private:

      Int();
      Int(const Int & i);
      Int & operator = (const Int & i);
  };
}

#endif
