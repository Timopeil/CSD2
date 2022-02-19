#include <iostream>
#include "effect.h"
#include "delay.h"
#include "Circbuffer.h"

Delay::Delay() : Delay(int 0, float 48000){};
Delay::Delay(int delay, float samplerate) : Effect(samplerate){
    Circbuffer Circbuffer(delay);
    std::cout << "Delay constructed, Delay: " << delay << " Samples\n";
}

Delay::~Delay(){
 std::cout << "Delay deconstructed\n";
}

void Delay::in(float sample){
  setEffectSampleIn(sample);
};

void Delay::tick(){
  Circbuffer.write(getEffectSampleIn(), delay);
  Circbuffer.tick();
  sample = Circbuffer.read();
};

float Delay::out(){
  return effectSampleOut();
};
