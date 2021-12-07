///////////////////////////////
// Instrument classification //
///////////////////////////////

#include <iostream>
#include <string>
#include "Instrument.h"

Instrument::Instrument(){}
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
  anInstrument.type = "note";
  std::cout << anInstrument.type; "\n";
  return 0;
}
