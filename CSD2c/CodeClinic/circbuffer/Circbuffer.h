#ifndef _CIRCBUFFER_H_
#define _CIRCBUFFER_H_
#include <iostream>

class Circbuffer{
public:
  Circbuffer(int size);
  ~Circbuffer();
  void setstart(int index);
  float read();
  void write(int index, float value);

private:
  int size;
  int index;
  int wrap();
};

#endif
