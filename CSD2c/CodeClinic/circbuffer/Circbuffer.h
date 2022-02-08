#ifndef _CIRCBUFFER_H_
#define _CIRCBUFFER_H_
#include <iostream>

class Circbuffer{
public:
  Circbuffer(int size);
  ~Circbuffer();
  float read();
  void write(float value, int delay);

private:
  int size;
  int writehead;
  int readhead;
  int wrap(int anyhead);
  float buffer[];
};

#endif
