#include <Arduino.h>
#include <iostream>


#include <libpq-fe.h> 

#include <WiFi.h>
#include <pgmspace.h>

#include <diviseur.h> // classe du diviseur de tension
#include <pulse.h>    // classe du lecteur de pools 


#include<secret.h> // fichier privé d'informations sur le wifi et numero de série
                    // pas disponible sur le git Hub



  // Establish a connection to the PostgreSQL database
   

void setup() {
  Serial.begin(115200);

  // Se connecter au réseau Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connexion au WiFi...");
  }
  Serial.println("Connexion WiFi établie !");

  

    // Check if the connection was successful
    if (PQstatus(connection) != CONNECTION_OK) {
      
        Serial.print("Connection to database failed: " );
        Serial.println(PQerrorMessage(connection));
        
        PQfinish(connection);
        
    }


}

pulse pulse1;
diviseur diviseur1;

void loop() {

  int timer = millis();

  float rythme;
  float pourcent;

  rythme = pulse1.calcul();
  pourcent = diviseur1.calcul();

  while (millis() < timer + 10000 )
  {
    
  }
  
  // envoi des données

    PGresult* data = PQexec(connection, "INSERT INTO records Values('$Num_Serie', '$rythme', '$pourcent')");
    PQclear(data);
    PQfinish(connection);

  
}


