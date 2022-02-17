#include "Circbuffer.h"
#include <iostream>


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
  std::cout << "\n**tick**\n\n";
}

void Circbuffer::write(float value, int delay){
  //FIX!, make a reset writehead function
  writehead = readhead;
  writehead += delay;
  writehead = wrap(writehead);
  buffer[writehead] = {value};
}

int Circbuffer::wrap(int anyhead){
  if (anyhead >= size){
    anyhead =- size;
    std::cout << "head wrapped \n";
  };
  return anyhead;
}
