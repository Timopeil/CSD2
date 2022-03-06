#ifndef _WAVESHAPER_H_
#define _WAVESHAPER_H_
#include "effect.h"

class Waveshaper : public Effect{

public:
  Waveshaper();
  Waveshaper(int buffersize, float saturation, float samplerate);
  ~Waveshaper();
  void tick();

//setters and getters saturation
  void setSaturation(float subjectsaturation);
  float getSaturation();
  float WSsample;


protected:
  float scaleSaturation(float SSsaturation);
  void wrap();
  int readhead;

  int buffersize;
  //type is set on init, cant be changed, unless new instance is created. #STC
  //int type;
  float saturation;

  float scaledSaturation;

  float* buffer[];
};

#endif
