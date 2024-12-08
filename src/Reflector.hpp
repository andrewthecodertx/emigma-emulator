#ifndef REFLECTOR_HPP
#define REFLECTOR_HPP

#include <string>

class Reflector {
public:
  Reflector(const std::string &wiring);
  char Encode(char c) const;

private:
  std::string wiring_;
};

#endif // REFLECTOR_HPP
