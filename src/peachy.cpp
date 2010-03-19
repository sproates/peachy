#include <exception>
#include <iostream>
#include <string>

#include "peachy.h"

namespace peachy {

  void print_usage(const char * exeName, std::ostream& outputStream) {
    outputStream << "Usage: " << exeName << " [options] [script]" << std::endl;
    outputStream << "Options:" << std::endl;
    outputStream << "  -h, --help                     Print this message and exit." << std::endl;
    outputStream << "  -r, --repl                     Run " << name << " in REPL mode." << std::endl;
    outputStream << "  -v, --version                  Print version information and exit." << std::endl;
  }

  void print_intro(std::ostream& outputStream) {
    outputStream << name << " " << version << std::endl;
  }

  void print_exception(std::exception& exception, std::ostream& outputStream) {
    outputStream << name << " exception: " << exception.what() << std::endl;
  }

  void print_fatal(std::string message, std::ostream & outputStream) {
    outputStream << "Fatal error: " << message << std::endl;
  }

  void print_invalid(const char * option, std::ostream & outputStream) {
    outputStream << "Invalid option: " << option << std::endl;
  }
}

