#include "sqr.h"
#include "math.h"

Sqr::Oscilator(float frequency, double samplerate) : type(sqr),frequency(frequency),
  amplitude(1.0), phase(0), sample(0), samplerate(samplerate)
{
  std::cout << "Sqr - constructor\n";
  std::cout << "Sqr: " << "\n" << "  frequency: " << frequency << "\n";
}



Sqr::~Sqr() {
  std::cout << "Sqr - destructor\n";
}


float Sqr::getSample() {
  return sample;
}

void Sqr::tick() {
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
void Sqr::setFrequency(float frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}

float Sqr::getFrequency()
{
  return frequency;
}
