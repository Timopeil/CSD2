#ifndef _Oscilator_H_
#define _Oscilator_H_
#include <iostream>

class Oscilator
{
public:
  //Constructor and destructor
  Oscilator(float frequency, double samplerate);
  ~Oscilator();

  //return the current sample
  float getSample();

  void tick();

  //getters and setters
  void setFrequency(float frequency);
  float getFrequency();

// private:
  float frequency;
  float amplitude;
  float phase;
  // sample contains the current sample
  float sample;
  double samplerate;
};

#endif
