#include "esp_log.h"
#include "arduino.h"


const int ledpin = 12;
void app_main() {
    pinMode(ledpin, OUTPUT);
}
void loop(){    
    digitalWrite(ledpin, HIGH);
    delay(1000);
    digitalWrite(ledpin, LOW);
    delay(1000);
}