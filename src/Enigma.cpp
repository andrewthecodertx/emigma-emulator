#include "Enigma.hpp"
#include <cctype>

Enigma::Enigma(const std::array<Rotor, 3> &rotors, const Reflector &reflector,
               const std::map<char, char> &plugboard)
    : rotors_(rotors), reflector_(reflector), plugboard_(plugboard) {}

void Enigma::SetRotorPositions(char left, char middle, char right) {
  rotors_[0].SetPosition(left);
  rotors_[1].SetPosition(middle);
  rotors_[2].SetPosition(right);
}

char Enigma::EncryptChar(char c) {
  if (!std::isalpha(static_cast<unsigned char>(c))) {
    return c; // Non-alphabetic: return as is
  }

  c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));

  StepRotors();

  // Plugboard in
  c = plugboard_.at(c);

  // Forward through rotors (right to left)
  c = rotors_[2].EncodeForward(c);
  c = rotors_[1].EncodeForward(c);
  c = rotors_[0].EncodeForward(c);

  // Reflect
  c = reflector_.Encode(c);

  // Backward through rotors (left to right)
  c = rotors_[0].EncodeBackward(c);
  c = rotors_[1].EncodeBackward(c);
  c = rotors_[2].EncodeBackward(c);

  // Plugboard out
  c = plugboard_.at(c);

  return c;
}

std::string Enigma::EncryptMessage(const std::string &msg) {
  std::string result;
  for (auto ch : msg) {
    if (std::isalpha(static_cast<unsigned char>(ch))) {
      result.push_back(EncryptChar(ch));
    } else {
      result.push_back(ch);
    }
  }
  return result;
}

void Enigma::StepRotors() {
  bool rightAtNotch = rotors_[2].AtNotch();
  bool middleAtNotch = rotors_[1].AtNotch();

  // Right rotor always steps
  rotors_[2].Advance();

  // Middle rotor steps if at notch or right rotor at notch
  if (middleAtNotch || rightAtNotch) {
    rotors_[1].Advance();
  }

  // Left rotor steps if middle rotor was at notch
  if (middleAtNotch) {
    rotors_[0].Advance();
  }
}
