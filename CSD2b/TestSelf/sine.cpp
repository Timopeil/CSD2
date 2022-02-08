#include "oscilator.h"
#include "sine.h"
#include "math.h"

void Oscilator::tick() {
  // NOTE 1. - frequency / SAMPLERATE can be implemented in a more efficient way
  // NOTE 2. - still need todo 'something' with the phase, see 04_sin_function
  phase += frequency / samplerate;
  sample = sin(M_PI * 2 * phase) * amplitude;
}
