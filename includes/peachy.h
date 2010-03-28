#ifndef PEACHY_PEACHY_H
#define PEACHY_PEACHY_H

#include <exception>
#include <iostream>

namespace peachy {

  // Print a message to an output stream describing how to use the CLI.
  void print_usage(const char * exeName, std::ostream & outputStream);

  // Print the peachy introductory message to an output stream.
  void print_intro(std::ostream & outputStream);

  // Prints an exception to an output stream.
  void print_exception(std::exception & exception, std::ostream & outputStream);

  // Print a 'fatal' message (to be used when we don't know what's happened).
  void print_fatal(std::string message, std::ostream & outputStream);

  // Print a message letting the user know the option they specified was invalid.
  void print_invalid(const char * option, std::ostream & outputStream);

  // The version identify of Peachy.
  const std::string version = "0.1";

  // The Peachy name.
  const std::string name = "Peachy";
}

#endif
