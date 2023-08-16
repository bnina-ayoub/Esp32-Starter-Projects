# Potentiometer-Based LED Intensity Regulator

This project regulates the intensity of an LED connected to GPIO 12 on an ESP32 development board using a potentiometer connected to GPIO 4.

## Requirements

* ESP32 development board
* Breadboard
* LED
* 220Ω resistor
* Potentiometer
* Arduino IDE
* ESP32 Arduino library

## Instructions

1. Connect the LED to GPIO 12 on the ESP32 development board.
2. Connect the anode of the LED to the positive rail of the breadboard.
3. Connect the cathode of the LED to the negative rail of the breadboard through the 220Ω resistor.
4. Connect the potentiometer to GPIO 4 on the ESP32 development board.
5. Open the Arduino IDE and import the ESP32 Arduino library.
6. Copy the code below into a new Arduino sketch.

```c++
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
```

7. Upload the code to the ESP32 development board.
8. The LED should light up, and its brightness should be proportional to the position of the potentiometer.

## Known Issues

* The LED may not light up if the potentiometer is not connected correctly.
* The LED may not be as bright as expected if the PWM frequency is not high enough.

## License

This project is licensed under the MIT License.

## Feedback

If you have any feedback on this project, please feel free to open an issue or submit a pull request.
