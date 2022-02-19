#include "Circbuffer.h"
#include <iostream>

Circbuffer::Circbuffer(){};

Circbuffer::Circbuffer(int size):size(size){
  std::cout << "buffer made with size: " << size << "\n";
  buffer = new float[size];
 for (int i = 0; i <= size; i++){
   buffer[i] = {0.};
 };
}

Circbuffer::~Circbuffer(){
}

float Circbuffer::read(){
 return buffer[readhead];
}

void Circbuffer::tick(){
  readhead ++;
  writehead ++;
  std::cout << "tick writehead before wrap : " << writehead << "\n";
  writehead = wrap(writehead);
  std::cout << "tick writehead after wrap : " << writehead << "\n";
  readhead = wrap(readhead);
  std::cout << "\n**tick**\n\n";
}

void Circbuffer::resetWritehead(){
  writehead = readhead;
}

void Circbuffer::write(float value, int delay){
  resetWritehead();
  writehead += delay;
  writehead = wrap(writehead);
  buffer[writehead] = {value};
}

int Circbuffer::wrap(int anyhead){
  if (anyhead >= size + 1){
    anyhead = 0;
    std::cout << "head wrapped \n";
  };
  return anyhead;
}
