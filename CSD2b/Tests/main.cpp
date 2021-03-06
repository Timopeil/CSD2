#include <iostream>
#include <thread>
#include "jack_module.h"
#include "oscilator.h"
#include "math.h"
//#include "sine.h"
#include "sqr.h"


int main(int argc,char **argv)
{
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();
  std::cout << "samplerate " << samplerate << '\n';
  Sqr::Oscilator sqr(220, samplerate);
  //Sine sine(220, samplerate);

  float amplitude = 0.15;
  //assign a function to the JackModule::onProces
  jack.onProcess = [&sqr, &amplitude](jack_default_audio_sample_t *inBuf,
    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = 0.75 * sqr.getSample();
      //sine.tick();
      sqr.tick();
    }
    amplitude = 0.5;
    return 0;
  };

  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        jack.end();
        break;
    }
  }

  //end the program
  return 0;
} // main()
