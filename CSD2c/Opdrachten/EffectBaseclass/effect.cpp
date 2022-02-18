#include "effect.h"
#include <iostream>

effect();
~effect();

//
float effectSampleIn();
float effectSampleOut();
//
void setDrywet(float drywet){
  drywet = dryWet;
};

float getDrywet(){
  return dryWet;
};

float applyDrywet(){
  sample = sample * dryWet + drySample * 1 - dryWet;
};

void tick();
//
void toggleBypass();
void setBypass(bool bypass);
//
