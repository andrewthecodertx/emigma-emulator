#ifndef ENIGMA_HPP
#define ENIGMA_HPP

#include "Reflector.hpp"
#include "Rotor.hpp"
#include <array>
#include <map>
#include <string>

class Enigma {
public:
  Enigma(const std::array<Rotor, 3> &rotors, const Reflector &reflector,
         const std::map<char, char> &plugboard);

  char EncryptChar(char c);
  std::string EncryptMessage(const std::string &msg);
  void SetRotorPositions(char left, char middle, char right);

private:
  void StepRotors();

  std::array<Rotor, 3> rotors_;
  Reflector reflector_;
  std::map<char, char> plugboard_;
};

#endif // ENIGMA_HPP
