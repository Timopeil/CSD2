#ifndef _sqr_H_
#define _sqr_H_
#include <iostream>

class Sqr
{
public:
  //Constructor and destructor
  Sqr(float frequency, double samplerate);
  ~Sqr();

  //return the current sample
  float getSample();
  // go to next sample
  void tick();

  //getters and setters
  void setFrequency(float frequency);
  float getFrequency();


#endif
