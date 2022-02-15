#include <iostream>

void LinInp(float x1, float y1, float x2, float y2){
float xplotf = (&x1 - &x2) * 0.5;
float yplotf = (&y1 - &y2) * 0.5;
float* xplot = &xplotf;
float* yplot = &yplotf;
};

int main() {
LinInp(4, 4, 2, 2);
float* xplot;
float* yplot;
std::cout << *xplot << " " << *yplot << "\n";
  return 0;
}
