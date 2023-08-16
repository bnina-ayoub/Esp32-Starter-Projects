#include "esp_log.h"
#include "arduino.h"

// Potentiometer is connected to GPIO 4 (Analog ADC1_CH6)
const int potPin = 4;
const int LedPin = 12;
// variable for storing the potentiometer value
int potValue = 0;

void setup() {
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  // Reading potentiometer value
  potValue = analogRead(potPin);
  // The maximum value of the potentiometer is 4096.
  // The LED's analog value should be 255 when the potentiometer is 
  //at its maximum. 
  //4095x = 255 <=> x = 0.06
  Serial.println(potValue);
  analogWrite(LedPin, potValue * 0.06);
  delay(500);
}