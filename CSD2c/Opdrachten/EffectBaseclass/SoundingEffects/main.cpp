#include "tremolo.h"
#include "delay.h"
#include "sqr.h"
#include "jack_module.h"
#include <iostream>
#include <thread>

int main(int argc,char **argv)
{
  bool debug = false;
  //creat jack JackModule
  JackModule jack;
  jack.init(argv[0]);
  //get samplerate from jack
  double samplerate = jack.getSamplerate();
  //create sound source parameters
  float amplitude = 0.5;
  float freq = 400;
  float squareSample = 0;
  //create Signal in this case its a Square wave
  Sqr sqr(freq, samplerate);
  //create Effect parameters
  Tremolo MyTremolo(4, 0.9, samplerate);
  float EffectSample = 0;
  Delay MyDelay(200, samplerate);
  //create output variable
  float sampleOut = 0;

  jack.onProcess = [&debug, &EffectSample, &MyTremolo, &MyDelay, &squareSample, &sqr, &sampleOut, &amplitude](jack_default_audio_sample_t *inBuf,
    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

      for(unsigned int i = 0; i < nframes; i++) {
        outBuf[i] = sampleOut*amplitude;
        //
        squareSample = sqr.genNextSample();
        //
        MyTremolo.setEffectSampleIn(squareSample);
        //
        MyDelay.setEffectSampleIn(MyTremolo.effectSampleOut());
        //
        EffectSample = MyDelay.effectSampleOut();
        //
        sampleOut = EffectSample;

        if (debug){
            std::cout << "for sample: " << i << "\n";
            std::cout << "oscilator sample, value: " << squareSample << "\n";
            std::cout << "effect sample, value: " << EffectSample <<'\n';
            std::cout << "out sample, value : " << sampleOut << '\n';
            std::cout << "\n ***Tick*** \n" << '\n';
        };
        //
        MyDelay.tick();
        MyTremolo.tick();

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
        case 'h':
          std::cout << "Hello world, i can be controlled" << '\n';
      }
    }

    //end the program
    return 0;


}
