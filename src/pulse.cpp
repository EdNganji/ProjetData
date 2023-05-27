  #include <pulse.h>
  


  pulse::pulse(byte pin) {
      
    }

    long pulse::calcul() {
      
        uint8_t rateValue;
    heartrate.getValue(heartratePin); ///< A1 foot sampled values
    rateValue = heartrate.getRate(); ///< Get heart rate value 
    if(rateValue)  {
        Serial.println(rateValue);
    }
    delay(20);
    }

    