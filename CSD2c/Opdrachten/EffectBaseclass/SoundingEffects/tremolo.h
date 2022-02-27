#ifndef _TREMOLO_H_
#define _TREMOLO_H_
#include <iostream>
#include "effect.h"
#include "sine.h"

class Tremolo : public Effect{
public:
  Tremolo();
  Tremolo(float frequency, float depth, float samplerate);
  ~Tremolo();
  void tick();
  void setDepth(float value);
  float getDepth();

protected:
  float depth;
  float frequency;
  Sine *lfo;
};

#endif
//lol
