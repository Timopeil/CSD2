#include "Inpol.h"
#include <iostream>

int main() {
  std::cout << "Nearest neighbour 2d : " << nnb(1, 5, 2) << "\n";
  std::cout << "Nearest neighbour 3d : " << nnb(1, 5, 4, 7, 2) << "\n";
  float xplot;
  float yplot;
  linear(-4, 4, 2.5, 8, &xplot, &yplot);
  std::cout << "\nLinear 2d : [" << xplot << " ; " << yplot << "]\n";
  float zplot;
  linear(7, 4, 5.2, -1, 6, -3, &xplot, &yplot, &zplot);
  std::cout <<  "Linear 3d : [" << xplot << " ; " << yplot << " ; " << zplot << "]\n";
  return 0;
}
