#include "sqr.h"
#include "math.h"

Sqr::Sqr() : Sqr(0, 0)
{}

Sqr::Sqr(float frequency, float samplerate) :
  Oscillator(frequency, samplerate)
{
  std::cout << "Sqr - constructor\n";
}

Sqr::~Sqr() {
  std::cout << "Sqr - destructor\n";
}

void Sqr::calcNextSample()
{
  std::cout << "oscilator phase: " << phase << "\n";
  // QuickFix:
  //.0001 else youll get rounding issues if used as nyquist oscillator
  if (phase >= 0.50000000000001) {
    sample = 1;
  } else {
    sample = -1;
  }
  sample *= amplitude;
}

// sqr.cpp is based on square.cpp by 'https://github.com/ciskavriezenga'
