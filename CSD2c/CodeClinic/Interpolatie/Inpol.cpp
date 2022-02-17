#include "Inpol.h"
#include <iostream>

float nnb(float a, float b, float value) {
  if (value >= (a - b)* 0.5){
    return a;
  } else{
    return b;
  };
};

//Nearest number of any plain, but i probably have to read back both plains.
//TODO make pointers so you can return both plains.
float nnb(float a, float b, float c, float d, float value) {
  return nnb(nnb(a, b, value),nnb(c, d, value), value);
};

//snum (=smallest number) returns lowest value including negatives
float snum(float a, float b){
    if (a <= b){return a;}else{return b;}
  };

//pos returns positive number if number is negative, returns input if number is positive.
float pos(float a){
  if (a <= 0){return a * -1;}else{return a;};
};

void linear(float x1, float y1, float x2, float y2, float *xplot, float *yplot){
  *xplot = pos(x1 - x2)*0.5 + snum(x1, x2);
  *yplot = pos(y1 - y2)*0.5 + snum(y1, y2);
};

//tlinear = target linear, returns the y of given x of the linear equation of the given points
float tlinear(float x1, float y1, float x2, float y2, float target){
 return snum(y1, y2) + target / (pos(x1 - x2) + snum(x1, x2)) * pos(y1 - y2);
};

void linear(float x1, float y1, float z1, float x2, float y2, float z2, float *xplot, float *yplot, float *zplot){
  *xplot = pos(x1 - x2)*0.5 + snum(x1, x2);
  *yplot = pos(y1 - y2)*0.5 + snum(y1, y2);
  *zplot = pos(z1 - z2)*0.5 + snum(z1, z2);
};

void tlinear(float x1, float y1, float z1, float x2, float y2, float z2, float target, float *yplot, float *zplot){
  *yplot = snum(y1, y2) + target / (pos(x1 - x2) + snum(x1, x2)) * pos(y1 - y2);
  *zplot = snum(z1, z2) + target / (pos(x1 - x2) + snum(x1, x2)) * pos(z1 - z2);
};
