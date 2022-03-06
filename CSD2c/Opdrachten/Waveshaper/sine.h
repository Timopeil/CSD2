#ifndef _SINE_H_
#define _SINE_H_
#include <iostream>
#include "oscillator.h"

class Sine : public Oscillator
{
public:
  //Constructor and destructor
  Sine();
  Sine(float frequency, float samplerate);
  ~Sine();

private:
  // calculate the next sample according to square calculation
  void calcNextSample() override;
};

#endif

// sine.h is based on square.h by 'https://github.com/ciskavriezenga'
