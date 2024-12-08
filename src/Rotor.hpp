#ifndef ROTOR_HPP
#define ROTOR_HPP

#include <string>

class Rotor {
public:
  Rotor(const std::string &wiring, char notch);

  void SetPosition(char c);
  void Advance();
  char EncodeForward(char c) const;
  char EncodeBackward(char c) const;
  bool AtNotch() const;

private:
  std::string wiring_;
  char notch_;
  int position_;
};

#endif // ROTOR_HPP
