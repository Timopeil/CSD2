#include "oscilator.h"
#include "sqr.h"
#include "math.h"

Sqr::Sqr(){
  void Oscilator::tick(float frequency, double samplerate) {
    //draws a square wave
    phase += frequency / samplerate;
    if (((int)phase & 1) == 0) {
      sample = 1;
    } else {
      sample = -1;
    }
  }
}
