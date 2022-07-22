#include "ESP8266WiFi.h"
#include <ESP8266HTTPClient.h>

const char* ssid = "Ittina"; //Enter SSID
const char* password = "@560037@"; //Enter Password
const char* endpoint = "127.0.0.1";

void setup(void)
{ 
  Serial.begin(115200);
  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
     delay(500);
     Serial.print("*");
     Serial.println(ssid);
  }
  
  Serial.println("");
  Serial.println("WiFi connection Successful");
  Serial.print("The IP Address of ESP8266 Module is: ");
  Serial.print(WiFi.localIP());// Print the IP address
}

void loop() 
{  
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    WiFiClient client;
    http.begin(client, "https://www.google.com");  //Specify request destination
    int httpCode = http.GET();     //Send the request 
    if (httpCode > 0) { //Check the returning code

      String payload = http.getString();   //Get the request response payload
      Serial.println(payload);                     //Print the response payload

    }

    http.end();
  }
  else {
    Serial.println("unable to connect");  
  }
  delay(50000);
}
