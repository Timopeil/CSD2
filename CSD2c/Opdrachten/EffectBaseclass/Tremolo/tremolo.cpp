#include <iostream>
#include "effect.h"
#include "sine.h"
#include "tremolo.h"

Tremolo::Tremolo() : Tremolo(0, 0, 48000){};
Tremolo::Tremolo(float frequency, float depth, float samplerate) :
Effect(samplerate){
  setBypass(false);
  setDrywet(1);
  lfo = new Sine(frequency, samplerate);
  std::cout << "Tremolo - constructed, lfo frequency: " << frequency
  << ", depth: " << depth <<'\n';
}

Tremolo::~Tremolo(){
  std::cout << "Tremolo - deconstructed\n";
}

void Tremolo::tick(){
  float lfosample = lfo->genNextSample();
  //Todo remake depth
  sample = getEffectSampleIn()*(lfosample+1);
}
