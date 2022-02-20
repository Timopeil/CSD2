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
  std::cout << "lfo value: " << lfosample <<'\n';
  sample = getEffectSampleIn()*((lfosample-depth+1)*0.25+0.5);
  std::cout << "\n**tick**\n\n";
}
