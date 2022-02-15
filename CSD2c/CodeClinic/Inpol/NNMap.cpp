#include <iostream>

// class NNMap{
// public:
// NNMap();
// ~NNMap();
//
// float NNMap(float value){
//  if (OldValue = NULL){
//    OldValue = value;
//    return value;
//    break;
//  };
//  median = (Oldvalue - value) * 0.5
//  if (value >= median){
//    return value;
//  } else {
//    return OldValue
//  }
// }
//
// private:
// float OldValue;
// float median;
// }
//
float NNMap(float a, float b, float value) {
  if (value >= (a - b)* 0.5){
    return a;
  } else{
    return b;
  };
};

int main() {

std::cout << NNMap(-1, -5, -3) << "\n";
return 0;
}
