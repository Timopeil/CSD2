
#include "oscilator.h"
#include "math.h"

Oscilator::Oscilator(float frequency, double samplerate) : frequency(frequency),
  amplitude(1.0), phase(0), sample(0), samplerate(samplerate)
{
  std::cout << "Oscilator - constructor\n";
}



Oscilator::~Oscilator() {
  std::cout << "Oscilator - destructor\n";
}

float Oscilator::getSample() {
  return sample;
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
