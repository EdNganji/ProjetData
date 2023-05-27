

#ifndef diviseur_h
#define diviseur_h

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif 


class diviseur
{
  public:
    const int Pindivten = A3;          
    float vIn;                                
    float vOut;
    int pourcentage;
    float Valeurlue;                   
    const float facteur = 5.128;               
    const float Vcc = 3.3;   

   diviseur(byte pin);
   long calcul();

    
};

#endif 
