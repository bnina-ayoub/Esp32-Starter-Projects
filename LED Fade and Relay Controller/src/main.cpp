#include "esp_log.h"
#include "arduino.h"

const int ledPin = 2;  //  Pin of LED
const int relayPin = 3;  //  Pin of Relay

//const int freq = 5000;
//const int ledChannel = 0;
//const int resolution = 8;


void setup() {
  // setting PWM properties

  //ledcSetup(ledChannel, freq, resolution);
  //ledcAttachPin(ledPin, ledChannel);

  pinMode(ledPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
 
}

void loop() {

 for (int i=0; i < 255; i++){
   // ledcWrite(ledChannel, i);
     analogWrite(ledPin, i);  
      delay(50);
  if(i == 255) {
    digitalWrite(relayPin, HIGH);
    delay(2000);      
 }

}
 
for (int i=255; i >= 0; i--){
    //ledcWrite(ledPin, i);
     analogWrite(ledPin, i);  
    delay(50);
    if(i == 0) {
    digitalWrite(relayPin, LOW);
    delay(2000);      
    }
 
 }


}