#include "sine.h"
#include "math.h"

Sine::Sine(float frequency) {
  // initialize members
  this->frequency = frequency;
  amplitude = 1.0;
  sample = 0;
  phase = 0;
  std::cout << "Sine - constructor\n";
}

Sine::~Sine() {}

float Sine::getSample() {
  return sample;
}

void Sine::tick() {
  phase += frequency / SAMPLERATE;
  sample = tan(M_PI * 2 * phase);
}

void Sine::setFrequency(float frequency)
{
  this->frequency = frequency;
}

float Sine::getFrequency()
{
  return frequency;
}
