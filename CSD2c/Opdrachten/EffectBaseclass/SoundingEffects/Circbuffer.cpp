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
  writehead = wrap(writehead);
  readhead = wrap(readhead);
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
  if (anyhead >= size){
    anyhead -= size;
  };
  return anyhead;
}
