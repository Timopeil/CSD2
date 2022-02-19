#ifndef _DELAY_H_
#define _DELAY_H_
#include <iostream>
#include "effect.h"
#include "Circbuffer.h"

class Delay : public Effect{
public:
  Delay();
  Delay(int delay, float samplerate);
  ~Delay();
  void in(float sample);
  float out();
  void tick();

private:
  int delay;
  Circbuffer Delaybuffer;
};

#endif
