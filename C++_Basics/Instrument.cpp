///////////////////////////////
// Instrument classification //
///////////////////////////////

#include <iostream>
#include <string>
#include "Instrument.h"

Instrument::Instrument(){
  type = "note";
}
Instrument::~Instrument(){}

class Idiophone: public Instrument {
public:
  Idiophone();
  ~Idiophone();
  std::string type;
};

Idiophone::Idiophone(){}
Idiophone::~Idiophone(){}

int main(){
  Instrument myInstrument;
  std::cout << myInstrument.type; "\n";
  return 0;
}
