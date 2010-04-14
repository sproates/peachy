#include "function.h"

#include <string>

#include "block.h"
#include "parameterlist.h"

namespace peachy {

  Function::Function(std::string name, ParameterList * parameterList, 
    Block * block) {
    this->name = name;
    this->parameterList = parameterList;
    this->block = block;
  }

  Function::~Function() {}

  std::string Function::getName() {
    return name;
  }

  ParameterList * Function::getParameterList() {
    return parameterList;
  }

  Block * Function::getBlock() {
    return block;
  }
}
