#ifndef _CIRCBUFFER_H_
#define _CIRCBUFFER_H_
#include <iostream>

class Circbuffer{
public:
  Circbuffer(int a);
  ~Circbuffer();
  float read();
  void write(float value, int delay);
  void tick();

private:
  int size;
  int writehead;
  int readhead;
  int wrap(int anyhead);
public:
  float *buffer;
};

#endif
