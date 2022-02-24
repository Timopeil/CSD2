#ifndef _SQR_H_
#define _SQR_H_
#include <iostream>
#include "oscillator.h"

class Sqr : public Oscillator
{
public:
  //Constructor and destructor
  Sqr();
  Sqr(float frequency, float samplerate);
  ~Sqr();

private:
  // calculate the next sample according to square calculation
  void calcNextSample() override;
};

#endif

// sqr.h is based on square.h by 'https://github.com/ciskavriezenga'
