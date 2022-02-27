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
  float freq = 800;
  float squareSample = 0;
  //create Signal in this case its a Square wave
  Sine sine(freq, samplerate);
  //create Effect parameters
  Tremolo MyTremolo(0.3, 0.2, samplerate);
  float EffectSample = 0;
  Delay MyDelay(20, samplerate);
  MyDelay.setDrywet(0.5);
  //create output variable
  float sampleOut = 0;

  jack.onProcess = [&debug, &EffectSample, &MyTremolo, &MyDelay, &squareSample, &sine, &sampleOut, &amplitude](jack_default_audio_sample_t *inBuf,
    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

      for(unsigned int i = 0; i < nframes; i++) {
        outBuf[i] = sampleOut*amplitude;
        //
        squareSample = sine.genNextSample();
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
            std::cout << "\n ***Tick*** \n\n";
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
          std::cout << "Hello! , I can be controlled" << '\n';
          break;

        //Controll Delay drywet
        //dupe code TODO make a function
        case '+':
          if(MyDelay.getDrywet() >= 1){
            std::cout << "Drywet can't be Increased" << '\n';
            break;}
          else{
            MyDelay.setDrywet(MyDelay.getDrywet() + 0.05);
            std::cout << MyDelay.getDrywet() << '\n';
            std::cout << "Delay DryWet Increased" << '\n';
          };
          break;
        case '-':
          if(MyDelay.getDrywet() <= 0){
            std::cout << "Drywet can't be decreased" << '\n';
            break;}
          else{
            MyDelay.setDrywet(MyDelay.getDrywet() - 0.05);
            //Bug reads back underflowed value if getDrywet = 0; code works ui problem.
            std::cout << MyDelay.getDrywet() <<"\nDelay DryWet decreased" << '\n';
          };
          break;
          //Controll Tremolo depth
          case '1':
            if(MyTremolo.getDepth() >= 1){
              std::cout << "Depth can't be Increased" << '\n';
              break;}
            else{
              MyTremolo.setDepth(MyTremolo.getDepth() + 0.05);
              std::cout << MyTremolo.getDepth() << '\n';
              std::cout << "Tremolo Depth Increased" << '\n';
            };
            break;
          case '2':
            if(MyTremolo.getDepth() <= 0){
              std::cout << "Depth can't be decreased" << '\n';
              break;}
            else{
              MyTremolo.setDepth(MyTremolo.getDepth() - 0.05);
              //Bug reads back underflowed value if getDepth = 0; code works ui problem.
              std::cout << MyTremolo.getDepth() <<"\nTremolo Depth decreased" << '\n';
            };
            break;



          //
        case 'd':
          if(debug){debug = false;}else{debug = true;};
          break;

      }
    }

    return 0;
}
