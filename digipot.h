/*
  digipot.h
  controls mcp4151 via SPI
  sam@samopper.com
  anchor science 2019
*/
class Digipot
{
  private:
    unsigned char csPin, step;
  public:
    Digipot(char chipselectPin, char s);
    unsigned char getStep();
    void adjustStep(bool adjustUp);
    void setStep(char s);
}