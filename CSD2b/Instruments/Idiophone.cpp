#include "Instrument.h"

class Idiophone: public Instrument {
public:
  Idiophone();
  ~Idiophone();
  std::string type;
};

Idiophone::Idiophone(){}
Idiophone::~Idiophone(){}

int main(){
  Idiophone anInstrument;
  anInstrument.type = "note";
  std::cout << anInstrument.type; "\n";
  return 0;
}
