/*
  mcp4151.css
  library to control mcp4151 digital potentiometer in wheatstone bridge balancing circuit
  Samuel Opper
  sam@samopper.com
  anchor science 2019

  mcp4151 datasheet: http://ww1.microchip.com/downloads/en/DeviceDoc/22060a.pdf
*/
#include "mcp4151.h"

MCP4151::MCP4151(char chipselectPin, char step){
  _chipselectPin = chipselectPin;
  _step = step;
}

void MCP4151::begin(){
  pinMode(_chipselectPin, OUTPUT);
  digitalWrite(_chipselectPin, HIGH);
  SPI.begin();
  setStep(_step);
}

unsigned int MCP4151::getResistance(){
  return _step * 39; // 39 ohms/step  
}

unsigned char MCP4151::getStep(){
  return _step;  
}

void MCP4151::setStep(char step){
  _step = step;
  digitalWrite(_chipselectPin, LOW);
  SPI.transfer(0x00);
  SPI.transfer(_step);
  digitalWrite(_chipselectPin, HIGH);
}

int MCP4151::adjust(char comparitorPin){ 
  if(digitalRead(comparitorPin))setStep(_step-1);
  else setStep(_step+1);
  return _step * 39 + 100;
}