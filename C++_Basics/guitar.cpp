////////////
// Guitar //
////////////

#include <Mat.h>
#include <string>

class MuzString{
public:
  MuzString();
  ~MuzString();
  int tenstion;
  int diameter;
  string material;
};

MuzString::MuzString(){};
MuzString::~MuzString(){};

class Guitar: Public Instrument{
public:
  Guitar();
  ~Guitar();
  string name;
  string type;
}

Guitar::Guitar(){};
Guitar::~Guitar(){};

string main() {
 Guitar myGuitar;
 cout << myGuitar << "\n";
 return 0;
}
