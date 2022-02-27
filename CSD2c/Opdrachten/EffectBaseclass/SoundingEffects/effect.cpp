#include "effect.h"
#include <iostream>

Effect::Effect(){};
Effect::Effect(float samplerate) : sample(0), samplerate(samplerate){
  this->samplerate = samplerate;
}

Effect::~Effect(){};

// Setters and getters for Drywet //  Apllies drywet as ratio
void Effect::setDrywet(float value){
  dryWet = value;
};

float Effect::getDrywet(){
  return dryWet;
};

void Effect::applyDrywet(){
  sample = drySample * dryWet + sample * 1 - dryWet;
};

//weet niet waar tick voor is. is later belangrijk denk ik.
//void tick();

// Toggles bypass // Sets bypass // Applies Bypass
void Effect::toggleBypass(){
  if (bypass){bypass = false;}else{bypass = true;}
};
void Effect::setBypass(bool bypass){
  bypass = bypass;
};
void Effect::applyBypass(){
  if (bypass){
    sample = drySample;
  };
};

// Getters and Setters for the Incomming data. as the sample is private
void Effect::setEffectSampleIn(float sample){
  drySample = sample;
};

float Effect::getEffectSampleIn(){
  return drySample;
};

// Function to be used in the main data path, aplies Effect and Drywet/Bypass
float Effect::effectSampleOut(){
  applyDrywet();
  applyBypass();
  return sample;
};
//
