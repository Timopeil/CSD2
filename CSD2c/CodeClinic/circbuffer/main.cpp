#include <iostream>
#include <thread>
#include "writeToFile.h"
#include "Circbuffer.h"
#include "sqr.h"

#define SAMPLERATE 44100

int main(int argc,char **argv)
{
  // with a 44100 samplerate and 882 frequency --> 50 samples for one cycle
  float freq = 882;
  // set delay to approximately a quarter cycle
  Circbuffer Circbuffer(200);

  //Circbuffer.logAllSettings();
  //log not present in Cirbuffer

  Sqr sqr(freq, SAMPLERATE);
  WriteToFile fileWriter("output.csv", true);

  // generate 200 samples
  // write sum of output of both the sine directly and the circBuffer to a file
  float squareSample = 0;
  for(int i = 0; i < 200; i++) {
    std::cout << "\n i="; std::cout << i;
    squareSample = sqr.genNextSample();
    Circbuffer.write(squareSample, 12);
    std::cout << Circbuffer.read();
    fileWriter.write(std::to_string(squareSample + Circbuffer.read()) + "\n");
    // Circbuffer.tick();
    // tick is included in circBuffer::read()
  }

  std::cout << "\n***** DONE ***** "
    << "\nWrote the sum of the a square oscillator and a "
    << "delayed value to output.csv." << std::endl;

  //end the program
  return 0;

}
