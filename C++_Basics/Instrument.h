#ifndef INSTRUMENT_H
#define INSTRUMENT_H

class Instrument{
  public:
    Instrument();
    ~Instrument();
    std::string play;
    bool pitch;
    bool microtonal;
    int numofpitch;
};

Instrument::Instrument(){}
Instrument::~Instrument(){}

int main(){
    
}
