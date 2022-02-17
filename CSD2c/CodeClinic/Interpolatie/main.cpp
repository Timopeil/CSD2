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
  linear(7, 4, 5.2, -2, 6, -3, &xplot, &yplot, &zplot);
  std::cout <<  "Linear 3d : [" << xplot << " ; " << yplot << " ; " << zplot << "]\n";
  std::cout << "\nTargetted linear 2d : [4 ; " << tlinear(-1, -4, 8, 2, 4) << "]\n";
  tlinear(7, 4, 6, 4, -1, 5, 5.5, &yplot, &zplot);
  std::cout << "Targetted linear 3d : [5.5 ; " << yplot << " ; " << zplot << "]\n";
  return 0;
}
