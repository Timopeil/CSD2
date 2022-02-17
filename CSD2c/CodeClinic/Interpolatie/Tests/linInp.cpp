#include <iostream>

void Linear(float x1, float y1, float x2, float y2, float *xplot, float *yplot){
*xplot = (x1 - x2) * 0.5;
*yplot = (y1 - y2) * 0.5;
};

int main() {
  float xplot;
  float yplot;
Linear(4, 4, 2, 2, &xplot, &yplot);
std::cout << xplot << " ; " << yplot << "\n";
  return 0;
}
