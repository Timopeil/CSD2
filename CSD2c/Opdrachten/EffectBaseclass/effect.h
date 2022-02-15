#ifndef _EFFECT_H_
#define _EFFECT_H_
#include <iostream>

class effect{
public:
  effect();
  ~effect();
  float setDrywet();
  float getDrywet();
  void tick();
  bool toggleBypass();
  void bypass();

protected:
  //drywet between [1,-1]?
  float dryWet;
  unsigned int samplerate;
  unsigned short int numOfChannels;
  bool bypass;


}

#endif
