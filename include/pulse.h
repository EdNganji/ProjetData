

#ifndef pulse_h
#define pulse_h

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif 


#include "DFRobot_Heartrate.h"

DFRobot_Heartrate heartrate(DIGITAL_MODE);

class pulse
{
  public:

    int heartratePin = 31;
    pulse (byte pin);
    long calcul();

    
};

#endif //#ifndef pulse_h
