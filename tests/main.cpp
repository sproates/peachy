#include <iostream>

#include "log.h"
#include "scriptsource.h"
#include "mockscriptsource.h"

int main() {

  peachy::Log * logger = new peachy::Log(&std::cout);
  peachy::ScriptSource * scriptSource =
    new peachy::test::MockScriptSource(logger);

  delete scriptSource;
  delete logger;

  return 0;
}
