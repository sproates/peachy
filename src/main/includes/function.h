#ifndef PEACHY_FUNCTION_H
#define PEACHY_FUNCTION_H

#include <string>

namespace peachy {

  class Block;
  class ParameterList;

  class Function {

    public:

      Function(std::string name, ParameterList * parameterList, Block * block);
      virtual ~Function();

      Block * getBlock();
      std::string getName();
      ParameterList * getParameterList();

    protected:

      Block * block;
      std::string name;
      ParameterList * parameterList;
  };
}

#endif
