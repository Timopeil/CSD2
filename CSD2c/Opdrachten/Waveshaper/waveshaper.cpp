#include "waveshaper.h"
#include "math.h"

Waveshaper::Waveshaper() : Waveshaper(48000, 0, 48000){};
Waveshaper::Waveshaper(int buffersize, float saturation, float samplerate) :
Effect(samplerate){
  //everything is commented out because a real wavetable is verry difficult
  //buffer = new float[buffersize];
  // fbIteration = calcFbIteration(saturation);
  // for (int i = 0; i <= buffersize; i++){
  //   buffer[i] = {0.};
  //};
//TODO include in effect constructor
  setBypass(false);
  setDrywet(0);
  setSaturation(saturation);
  std::cout << "Waveshaper - constructed, type: arctan " << "saturation: " << saturation << '\n';
  //std::cout << "scaled saturation: "<< scaledSaturation << '\n';
}

Waveshaper::~Waveshaper(){
  std::cout << "Waveshaper - deconstructed\n";
}

float Waveshaper::scaleSaturation(float SSsaturation){
  //scaling to 16 is about the point everything turns into a squarewave;
  //std::cout << "saturation scaled from: "<< saturation << " to: "<< scaledSaturation << '\n';
  return 16 * saturation + 1;
};

//setters and getters saturation
void Waveshaper::setSaturation(float subjectsaturation){
  //std::cout << "subject saturation: "<< subjectsaturation << '\n';
  saturation = subjectsaturation;
  scaledSaturation = scaleSaturation(subjectsaturation);
  //std::cout << "setter scaled saturation: "<< scaledSaturation << '\n';
};

float Waveshaper::getSaturation(){
  //std::cout << saturation << '\n';
  return saturation;
};

void Waveshaper::wrap(){
 if (readhead >= buffersize){
   readhead = 0;
 }
};

//main function to be included in main signal path/
void Waveshaper::tick(){
  //not a waveshaper but it does distorion
  //std::cout << "sample pre calculus: "<< sample << '\n';
  WSsample = (atan( pow(sqrt(2), scaledSaturation) * sample)) / sqrt(scaledSaturation);
  //std::cout << "sample post calculus: "<< WSsample << '\n';
  //std::cout << "\n***tick***\n" << '\n';
  sample = WSsample;
};
