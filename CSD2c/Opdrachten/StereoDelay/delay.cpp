#include <iostream>
#include "effect.h"
#include "delay.h"
#include "Circbuffer.h"

Delay::Delay() : Delay(0, 48000){};
Delay::Delay(int delay, float samplerate) : Effect(samplerate){
    setBypass(false);
    setDrywet(1);
    Delaybuffer = new Circbuffer(delay);
    std::cout << "Delay constructed, Delay: " << delay << " Samples\n";
}

Delay::~Delay(){
 std::cout << "Delay - deconstructed\n";
}

void Delay::tick(){
  Delaybuffer->write(getEffectSampleIn(), delay);
  Delaybuffer->tick();
  sample = Delaybuffer->read();
  //std::cout << "\n**tick**\n\n";
};
