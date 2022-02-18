#ifndef _EFFECT_H_
#define _EFFECT_H_
#include <iostream>

class effect{
public:
  effect();
  ~effect();

//
  float effectSampleIn();
  float effectSampleOut();
  float effectSampleIn_sc();
//
  void setDrywet();
  float getDrywet();
  float applyDrywet();
  void tick();
//
  void toggleBypass();
  void setBypass(bool bypass);
//


protected:
  //drywet between [0, 1]
  float drySample;
  float sample;
  float scSample;
  float dryWet;
  unsigned int samplerate;
  unsigned short int numOfChannels;
  bool bypass;
  bool midSide;
};

#endif
