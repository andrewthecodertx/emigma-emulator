#include "Enigma.hpp"
#include "Reflector.hpp"
#include "Rotor.hpp"
#include <array>
#include <iostream>
#include <map>

int main() {
  std::string rotorI_wiring = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
  std::string rotorII_wiring = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
  std::string rotorIII_wiring = "BDFHJLCPRTXVZNYEIWGAKMUSQO";

  Rotor rotorI(rotorI_wiring, 'Q');
  Rotor rotorII(rotorII_wiring, 'E');
  Rotor rotorIII(rotorIII_wiring, 'V');

  std::string reflectorB_wiring = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
  Reflector reflectorB(reflectorB_wiring);

  // Plugboard: for example, swap A<->B and C<->D
  std::map<char, char> plugboard;
  for (char c = 'A'; c <= 'Z'; ++c) {
    plugboard[c] = c;
  }
  plugboard['A'] = 'B';
  plugboard['B'] = 'A';
  plugboard['C'] = 'D';
  plugboard['D'] = 'C';

  std::array<Rotor, 3> rotors = {rotorI, rotorII, rotorIII};
  Enigma enigma(rotors, reflectorB, plugboard);
  enigma.SetRotorPositions('A', 'A', 'A');

  std::string plaintext = "HELLOWORLD";
  std::string ciphertext = enigma.EncryptMessage(plaintext);
  std::cout << "Plaintext:  " << plaintext << "\n";
  std::cout << "Ciphertext: " << ciphertext << "\n";

  // Decrypt with same settings
  enigma.SetRotorPositions('A', 'A', 'A');
  std::string decrypted = enigma.EncryptMessage(ciphertext);
  std::cout << "Decrypted:  " << decrypted << "\n";
}
