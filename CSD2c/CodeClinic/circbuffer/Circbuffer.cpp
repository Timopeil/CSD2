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
  readhead ++;
  writehead ++;
  wrap(writehead);
  return buffer[wrap(readhead)];
}

void Circbuffer::write(float value, int delay){
  buffer[wrap(writehead+delay)] = {value};
}

int Circbuffer::wrap(int anyhead){
  // if (anyhead >= 2 * (size - 1)){
  //   *error = true;
  };
  if (anyhead >= size){
    anyhead = anyhead - size;
  };
  return anyhead;
}

int main(){

}
