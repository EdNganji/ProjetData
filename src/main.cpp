#include <Arduino.h>
#include <iostream>


#include <libpq-fe.h> 

#include <WiFi.h>
#include <pgmspace.h>

#include <diviseur.h> // classe du diviseur de tension
#include <pulse.h>    // classe du lecteur de pools 


#include<wificonn.h>



  // Establish a connection to the PostgreSQL database
    PGconn* connection = PQconnectdb("dbname=dvdrental user=postgres password=admin host=192.168.0.36 port=5432");

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

    // Execute a query
    PGresult* result = PQexec(connection, "SELECT * FROM city");

    // Check if the query was successful
    if (PQresultStatus(result) != PGRES_TUPLES_OK) {
        Serial.print( "Query failed: " );
        Serial.println( PQresultErrorMessage(result) );
        PQclear(result);
        PQfinish(connection);

    }

    // Process the query result
    int num_rows = PQntuples(result);
    int num_cols = PQnfields(result);

    for (int row = 0; row < num_rows; ++row) {
        for (int col = 0; col < num_cols; ++col) {
            Serial.println( PQgetvalue(result, row, col) );
        }
        Serial.println();
    }

    // Clean up
    PQclear(result);
    PQfinish(connection);

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
  
  // Execute a query
    PGresult* result = PQexec(connection, "INSERT INTO records Values('$Num_Serie', '$rythme', '$pourcent')");


  // put your main code here, to run repeatedly:
}


