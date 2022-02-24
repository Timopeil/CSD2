#ifndef _EFFECT_H_
#define _EFFECT_H_
#include <iostream>

class Effect{
public:
  Effect();
  Effect(float samplerate);
  ~Effect();

//
  void setEffectSampleIn(float sample);
  float getEffectSampleIn();
  float effectSampleOut();
  float effectSampleIn_sc();

//
  void setDrywet(float dryWet);
  float getDrywet();
  void applyDrywet();
  //void tick();
//
  void toggleBypass();
  void setBypass(bool bypass);
  void applyBypass();
//
  //multichannel stuff TODO
  //float panning;


protected:
  //drywet between [0, 1]
  float drySample;
  float sample;
  //float scSample;
  float dryWet;
  float samplerate;
  bool bypass;
  // multichannel stuff unused //TODO
  short unsigned int numOfChannels;
  bool midSide;
  //ignore messy debug code,
  bool debug;
};

#endif
