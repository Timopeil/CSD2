#include <iostream>
#include <thread>
#include "writeToFile.h"
#include "delay.h"
#include "sqr.h"

#define SAMPLERATE 44100

int main(int argc,char **argv)
{
  // with a 44100 samplerate and 882 frequency --> 50 samples for one cycle
  float freq = 4000;
  // set delay
  Delay MyDelay(20, SAMPLERATE);
  // create Signal in this case its a Square wave
  Sqr sqr(freq, SAMPLERATE);
  WriteToFile fileWriter("output.csv", true);

  // generate 100 samples
  // write sum of output of Oscillator and Effect to a file
  float squareSample = 0;
  float sampleOut = 0;
  float EffectSample = 0;
  for(int i = 0; i < 100; i++) {
    std::cout << "for sample: " << i << "\n";
    //
    squareSample = sqr.genNextSample();
    std::cout << "oscilator sample, value: " << squareSample << "\n";
    //
    EffectSample = MyDelay.effectSampleOut();
    std::cout << "effect sample, value: " << EffectSample <<'\n';
    //
    sampleOut = (squareSample + EffectSample) * 0.5;
    std::cout << "out sample, value : " << sampleOut << '\n';
    //
    MyDelay.setEffectSampleIn(squareSample);
    MyDelay.tick();
    fileWriter.write(std::to_string(sampleOut) + "\n");
    // Circbuffer.tick();
    // tick is included in circBuffer::read()
  }

  std::cout << "\n***** DONE ***** "
    << "\nWrote the sum of the a square oscillator and a "
    << "delayed value to output.csv." << std::endl;

  //end the program
  return 0;

}
