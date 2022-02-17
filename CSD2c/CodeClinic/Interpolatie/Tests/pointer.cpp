#include <iostream>

int main() {
  float myfloat = 7004;
  float* mypointer = &myfloat;
std::cout << *mypointer << "\n";
  return 0;
}
