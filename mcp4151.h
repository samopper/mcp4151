/*
  mcp4151.h
  library to control mcp4151 digital potentiometer in wheatstone bridge balancing circuit
  Samuel Opper
  sam@samopper.com
  anchor science 2019

  mcp4151 datasheet: http://ww1.microchip.com/downloads/en/DeviceDoc/22060a.pdf
*/
#pragma once
#include <SPI.h>
#include "Arduino.h"
class MCP4151
{
  private:
    unsigned char _chipselectPin, _step;
  public:
    MCP4151(char chipselectPin, char step);
    void begin();
    unsigned int getResistance();
    unsigned char getStep();
    void setStep(char step);
    int adjust(char comparitorPin);
};
