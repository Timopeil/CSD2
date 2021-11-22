//////////////////////////////////////////
// Marblebox what the heck is a class?? //
//////////////////////////////////////////

#include <iostream>

class Colour{
public:
  Colour();
  ~Colour();
  int red;
  int green;
  int blue;
  int alpha;
};

Colour::Colour(){
  Colour.red = 255
  Colour.blue = 69
  Colour.green = 255
  Colour.alpha = 0
}
Colour::~Colour(){}

///////////////////////////////////

class Position{
public:
  Position();
  ~Position();
  int x;
  int y;
  int z;
};

Position::Position(){}
Position::~Position(){}

///////////////////////////////////

class Marble{
public:
  Marble();
  ~Marble();
  SetColour();
  Colour Colour;
  int diameter;
  int x;
  int y;
  int z;
};

Marble::SetColour(){
  Colour.red = rand() % 255;
  Colour.green = 69;
  Colour.blue = rand() % 255;
}

Marble::Marble(){
  SetColour();
  Marble.x = 0;
  Marble.y = 0;
  Marble.z = 0;
}

Marble::~Marble(){}

int main(){
  Marble Marble_1;
  std::cout << " Marble_1 = red = "; Marble_1.Colour.red; "green = "; Marble_1.Colour.green; "blue = "; Marble_1.Colour.blue >> std::endl;
return 0;
}
