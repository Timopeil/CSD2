#include <iostream>
#include "effect.h"
#include "sine.h"
#include "tremolo.h"

Tremolo::Tremolo() : Tremolo(0, 0, 48000){};
Tremolo::Tremolo(float frequency, float dep, float samplerate) :
Effect(samplerate){
  depth = dep;
  setBypass(false);
  setDrywet(1);
  lfo = new Sine(frequency, samplerate);
  std::cout << "Tremolo - constructed, lfo frequency: " << frequency
  << ", depth: " << depth <<'\n';
}

Tremolo::~Tremolo(){
  std::cout << "Tremolo - deconstructed\n";
}

//main function to be included in main program
void Tremolo::tick(){
  float lfosample = lfo->genNextSample()*depth;
  sample = getEffectSampleIn()*(lfosample + 1);
}

//getters and setters for depth as they are protected
void Tremolo::setDepth(float value){
  depth = value;
};
float Tremolo::getDepth(){
  return depth;
};
