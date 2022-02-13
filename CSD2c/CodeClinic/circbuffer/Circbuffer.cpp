#include "Circbuffer.h"
#include <iostream>


Circbuffer::Circbuffer(int size){
  float buffer[size] = {0.};
 for (int i = 0; i <= size; i++){
   buffer[i] = 0.;
 };
}

Circbuffer::~Circbuffer(){

}

float Circbuffer::read(){
  std::cout << "\n debug: read . readhead = "; std::cout << readhead;
  readhead ++;
  writehead ++;
  wrap(writehead);
  wrap(readhead);
  return buffer[readhead];
}

void Circbuffer::write(float value, int delay){
  //FIX!, make a reset writehead function
  writehead = readhead;
  writehead += delay;
  wrap(writehead);
  buffer[writehead] = {value};
}

int Circbuffer::wrap(int anyhead){
  // if (anyhead >= 2 * (size - 1)){
  //   *error = true;
  //};
  while (anyhead >= size){
    anyhead -= size;
    std::cout << "\n debug: Wrap loop";
  };
  return anyhead;
}
