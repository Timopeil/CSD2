#ifndef _INPOL_H_
#define _INPOL_H_
#include <iostream>

float nnb(float a, float b, float value);
// float Alphaplain;
// float Betaplain;
float nnb(float a, float b, float c, float d, float vlaue);
float snum(float a, float b);
float pos(float a);
void linear(float x1, float y1, float x2, float y2, float *xplot, float *yplot);
void linear(float x1, float y1, float z1, float x2, float y2, float z2, float *xplot, float *yplot, float *zplot);
float tlinear(float x1, float y1, float x2, float y2, float target);
void tlinear(float x1, float y1, float z1, float x2, float y2, float z2, float target, float *yplot, float *zplot);
// void cubic();
// void cubic();

#endif
