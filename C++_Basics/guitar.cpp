////////////
// Guitar //
////////////

#include <iostream>
#include <string>
#include "Instrument.h"

class MuzString{
public:
  MuzString();
  ~MuzString();
  int tenstion;
  int diameter;
  std::string material;
};

MuzString::MuzString(){};
MuzString::~MuzString(){};

class Guitar: Public Instrument{
public:
  Guitar();
  ~Guitar();
  std::string name;
  std::string type;
}

Guitar::Guitar(){};
Guitar::~Guitar(){};

int main() {
 Guitar myGuitar;
 std::cout << myGuitar << "\n";
 return 0;
}
