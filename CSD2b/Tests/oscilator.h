#ifndef _OSCILATOR_H_
#define _OSCILATOR_H_
#include <iostream>
#include <string>

class Oscilator
{
public:
  //Constructor and destructor
  Oscilator(float frequency, double samplerate);
  ~Oscilator();

  //return the current sample
  float getSample();
  // go to next sample
  void tick();

  //getters and setters
  void setFrequency(float frequency);
  float getFrequency();

  std::string type;
  float frequency;
  float amplitude;
  float phase;
  // sample contains the current sample
  float sample;
  double samplerate;
};

#endif
