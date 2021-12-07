#ifndef INSTRUMENT_H
#define INSTRUMENT_H

class Instrument{
  public:
    Instrument();
    Instrument::Instrument();
    ~Instrument();
    std::string play;
    bool pitch;
    bool microtonal;
    int numofpitch;
    string type;
};

#endif
