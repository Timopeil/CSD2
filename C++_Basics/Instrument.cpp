///////////////////////////////
// Instrument classification //
///////////////////////////////

#include <iostream>
#include <string>

class Instrument{
  public:
    Instrument();
    ~Instrument();
    std::string play;
    bool pitch;
    bool microtonal;
    int numofpitch;
};

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
  Idiophone anInstrument;
  anInstrument.type = "note";
  std::cout << anInstrument.type; "\n";
  return 0;
}
