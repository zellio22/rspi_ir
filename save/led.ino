/*
 * Demo PlatformIO - ESP32 - ESP8266 - Blink a Led
 * Turns on an LED on for one second, then off for one second, repeatedly.
 * projetsdiy.fr - diyprojects.io
 */

#include <Arduino.h>

#define LED_BUILTIN 15

void setup()
{
  // initialize LED digital pin as an output.
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);
  // wait for a second
  delay(1000);
  // turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("Blink");
   // wait for a second
  delay(1000);
}