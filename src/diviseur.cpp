  #include <diviseur.h>
  
  
  diviseur::diviseur(byte pin) {
      
    }

    long diviseur::calcul() {

    Valeurlue = analogRead(Pindivten);    // read the current sensor value (0 - 1023) 
    vOut = (Valeurlue / 1024) * Vcc;             // convert the value to the real voltage on the analog pin
    vIn =  vOut * facteur;                               // convert the voltage on the source by multiplying with the factor

    Serial.print("la tension est ");             
    Serial.print(vIn);
    Serial.println("V");

    pourcentage = (vIn * 100)/ vOut;

    Serial.print("le pourcentage est ");             
    Serial.print(pourcentage);
    Serial.println(" %");
      
    }

   