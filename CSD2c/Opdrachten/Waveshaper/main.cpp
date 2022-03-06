#include "waveshaper.h"
#include "sine.h"
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
  float sineSample = 0;
  //create Signal in this case its a Sinewave
  Sine sine(freq, samplerate);
  //create Effect parameters
  Waveshaper MyWS(48000, 0.8, samplerate);
  float EffectSample;
  //create output variable
  float sampleOut = 0;

  jack.onProcess = [&debug, &EffectSample, &MyWS, &sineSample, &sine, &sampleOut, &amplitude](jack_default_audio_sample_t *inBuf,
    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

      for(unsigned int i = 0; i < nframes; i++) {
        outBuf[i] = sampleOut*amplitude;
        //
        sineSample = sine.genNextSample();
        //
        MyWS.setEffectSampleIn(sineSample);
        //
        MyWS.tick();
        //
        EffectSample = MyWS.effectSampleOut();
        sampleOut = MyWS.WSsample;

        if (debug){
            std::cout << "for sample: " << i << "\n";
            std::cout << "oscilator sample, value: " << sineSample << "\n";
            std::cout << "effect sample, value: " << EffectSample <<'\n';
            std::cout << "out sample, value : " << sampleOut << '\n';
            std::cout << "\n***Tick*** \n\n";
        };
        //


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
          std::cout << "Hello! , I can be controlled!" << '\n';
          break;

        //Controll DSaturation
        //dupe code TODO make a function Write a controll class? or file
        case '+':
          if(MyWS.getSaturation() >= 0.999){
            std::cout << "Waveshaper Saturation can't be increased" << '\n';
            break;
            }
          if(MyWS.getSaturation() >= 0.96){
            MyWS.setSaturation(1);
            std::cout << "Waveshaper Saturation is now at 1" << '\n';}
          else{
            MyWS.setSaturation(MyWS.getSaturation() + 0.05);
            std::cout << MyWS.getSaturation() <<"\nWaveshaper Saturation increased" << '\n';
          };
          break;
        case '-':
          if(MyWS.getSaturation() <= 0){
            std::cout << "Waveshaper Saturation can't be decreased" << '\n';
            break;}
          if(MyWS.getSaturation() <=0.03){
            MyWS.setSaturation(0);
            std::cout << MyWS.getSaturation() <<"Waveshaper Saturation is now at 0" << '\n';
          }
          else{
            MyWS.setSaturation(MyWS.getSaturation() - 0.02);
            std::cout << MyWS.getSaturation() <<"\nWaveshaper Saturation decreased" << '\n';
          };
          break;

          //d from dont worry about this lines of code.
        case 'd':
          if(debug){debug = false;}else{debug = true;};
          break;
      }
    }
    return 0;
}
