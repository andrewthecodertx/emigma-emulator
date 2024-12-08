#include "Reflector.hpp"

Reflector::Reflector(const std::string &wiring) : wiring_(wiring) {}

char Reflector::Encode(char c) const { return wiring_[c - 'A']; }
