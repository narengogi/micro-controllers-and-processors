#include <SPI.h>
#include <DMD.h>
#include <TimerOne.h>
#include "SystemFont5x7.h"
#include "Arial_black_16.h"
//#include <ESP8266WiFi.h>

#define ROW 1
#define COLUMN 1
#define FONT Arial_Black_16

DMD led_module(ROW, COLUMN);

const char* ssid = "";
const char* pass = "@560037@";

void scan_module()
{
  led_module.scanDisplayBySPI();
}

void setup()
{
//  WiFi.mode(WIFI_STA);
//  WiFi.begin(ssid, pass);
  Serial.begin(9600);
  Timer1.initialize(3000);
  Timer1.attachInterrupt(scan_module);
  led_module.clearScreen( true );
}
void loop()
{
    const char* myString = "Bully fans club";
    if (Serial.available()) {
        Serial.begin(115200);
        myString = Serial.read();
    }
    led_module.selectFont(FONT);
    led_module.drawMarquee(myString, 23, (32 * ROW), 0);
    long start = millis();
    long timming = start;
    boolean flag = false;
    while (!flag)
    {
      if ((timming + 20) < millis()) 
      {
        flag = led_module.stepMarquee(-1, 0);
        timming = millis();
      }
    }
    Serial.println("");
  }
