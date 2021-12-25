#include "sine.h"
#include "math.h"

Sine::Sine(float frequency, double samplerate) : frequency(frequency),
  amplitude(1.0), phase(0), sample(0), samplerate(samplerate)
{
  std::cout << "Sine - constructor\n";
}



Sine::~Sine() {
  std::cout << "Sine - destructor\n";
}


float Sine::getSample() {
  return sample;
}

void Sine::tick() {
  // NOTE 1. - frequency / SAMPLERATE can be implemented in a more efficient way
  // NOTE 2. - still need todo 'something' with the phase, see 04_sin_function
  phase += frequency / samplerate;
  sample = sin(M_PI * 2 * phase) * amplitude;
}

//getters and setters
void Sine::setFrequency(float frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}

float Sine::getFrequency()
{
  return frequency;
}
