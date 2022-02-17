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
    if (a < b){return a;}else{return b;}
  };

//nnum (=negative number) returns positive number if number is negative, returns input if number is positive.
float nnum(float a){
  if (a < 0){return a * -1;}else{return a;};
};

void linear(float x1, float y1, float x2, float y2, float *xplot, float *yplot){
  *xplot = nnum(x1 - x2)*0.5 + snum(x1, x2);
  *yplot = nnum(y1 - y2)*0.5 + snum(y1, y2);
};

void linear(float x1, float y1, float z1, float x2, float y2, float z2, float *xplot, float *yplot, float *zplot){
  *xplot = nnum(x1 - x2)*0.5 + snum(x1, x2);
  *yplot = nnum(y1 - y2)*0.5 + snum(y1, y2);
  *zplot = nnum(z1 - z2)*0.5 + snum(z1, z2);
};
