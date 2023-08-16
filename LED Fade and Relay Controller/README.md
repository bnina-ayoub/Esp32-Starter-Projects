# LED and Relay Control

This project controls an LED and a relay using PWM on the ESP32. The LED is connected to GPIO 2, and the relay is connected to GPIO 3.

## Requirements

* ESP32 development board
* Breadboard
* LED
* 220Ω resistor
* Relay
* Arduino IDE
* ESP32 Arduino library

## Instructions

1. Connect the LED to GPIO 2 on the ESP32 development board.
2. Connect the anode of the LED to the positive rail of the breadboard.
3. Connect the cathode of the LED to the negative rail of the breadboard through the 220Ω resistor.
4. Connect the relay to GPIO 3 on the ESP32 development board.
5. Open the Arduino IDE and import the ESP32 Arduino library.
6. Copy the code below into a new Arduino sketch.

```c++
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
```


7. Upload the code to the ESP32 development board.
8. The LED should fade in and out, and the relay should turn on and off.

## Known Issues

* The LED may not fade smoothly if the PWM frequency is not high enough.
* The relay may not turn on or off if the pin is not configured correctly.

## License

This project is licensed under the MIT License.

## Feedback

If you have any feedback on this project, please feel free to open an issue or submit a pull request.
