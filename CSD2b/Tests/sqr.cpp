#include "oscilator.h"
#include "sqr.h"
#include "math.h"


Oscilator::Oscilator(float frequency , double samplerate) : frequency(frequency),
  amplitude(1.0), phase(0), sample(0), samplerate(samplerate), type("sqr"),{}


//Sqr constructor and deconstructor

Sqr::Sqr(){
  Oscilator sqrOscilator
  sqrOscilato
    std::cout << "Sqr - constructor\n";
    std::cout << "Sqr: " << "\n" << "  frequency: " << frequency << "\n";
  }

Sqr::~Sqr() {
  std::cout << "Sqr - destructor\n";
}

//Main code
float Oscilator::getSample() {
  return sample;
}

void Oscilator::tick() {
  // NOTE 1. - frequency / SAMPLERATE can be implemented in a more efficient way
  // NOTE 2. - still need todo 'something' with the phase, see 04_sin_function
  phase += frequency / samplerate;
  if (((int)phase & 1) == 0) {
    sample = 1;
  } else {
    sample = -1;
  }
}

//getters and setters
void Oscilator::setFrequency(float frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}

float Oscilator::getFrequency()
{
  return frequency;
}
