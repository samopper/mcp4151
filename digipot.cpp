/*
  digipot.css
  controls mcp4151 via SPI
  sam@samopper.com
  anchor science 2019

  mcp4151 datasheet: http://ww1.microchip.com/downloads/en/DeviceDoc/22060a.pdf
*/
#include "digipot.h"

DigiPot::DigiPot(char chipselectPin, char s){
  this->csPin = chipselectPin;
  pinMode(chipselectPin, OUTPUT);
  this->step = s;
  this->setStep(this->step);
}

unsigned char Digipot::getStep(){
  return this->step*78;  
}

void DigiPot::adjustStep(bool adjustUp){
  digitalWrite(csPin, LOW);
  if(adjustUp){
    this->step++;
    SPI.transfer(0x04);
  } 
  else{
    this->step--;
    SPI.transfer(0x08);
  } 
  digitalWrite(cs, HIGH);
}

void DigiPot::setStep(char s){
  this->step = s;
  digitalWrite(CS, LOW);
  SPI.transfer(0x00);
  SPI.transfer(step);
  digitalWrite(CS, HIGH);
}