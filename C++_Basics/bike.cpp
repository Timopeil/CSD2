#include <iostream>

class Wheel {
public:
  Wheel();
  ~Wheel();
  int diameter;
};

Wheel::Wheel(){
  diameter = 10;
  std::cout << "Wheel::Wheel " << diameter << std::endl;
}
Wheel::~Wheel(){
  std::cout << "Wheel::~Wheel " << std::endl;
}

class Bike {
public:
  Bike();
  ~Bike();
  Wheel frontwheel;
  Wheel rearwheel;
};

Bike::Bike(){
  std::cout << "Bike::Bike " << std::endl;
  std::cout << "Kaboom" << std::endl;
}
Bike::~Bike(){
  std::cout << "Bike::~Bike " << std::endl;
}


int main(){
  Bike myBike;
return 0;
}
