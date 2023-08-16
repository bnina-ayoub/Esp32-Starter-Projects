# ESP32 LED Controller with WiFi Control

This project controls an LED on an ESP32 development board using WiFi. The LED is connected to GPIO 27, and the WiFi connection is configured using the `SSID` and `PASSWORD` variables.

## Requirements

* ESP32 development board
* Breadboard
* LED
* 220Ω resistor
* Arduino IDE
* ESP32 Arduino library

## Instructions

1. Connect the LED to GPIO 27 on the ESP32 development board.
2. Connect the anode of the LED to the positive rail of the breadboard.
3. Connect the cathode of the LED to the negative rail of the breadboard through the 220Ω resistor.
4. Open the Arduino IDE and import the ESP32 Arduino library.
5. Copy the code below into a new Arduino sketch.

```c++
#include "esp_log.h"
#include "Arduino.h"
#include "WiFi.h"
#include "HTTPClient.h"

const int ledPin = 27;  //  Pin of LED
const int ButtonPin = 4;  //  Pin of Relay
const int potPin = 35;  //  Pin of Relay
int value = 0;
int coef = 0;
//const int freq = 5000;
//const int ledChannel = 0;
//const int resolution = 8;


void setup() {
  // setting PWM properties

  //ledcSetup(ledChannel, freq, resolution);
  //ledcAttachPin(ledPin, ledChannel);
Serial.begin(115200);
delay(1000);
 pinMode(ledPin, OUTPUT);
 pinMode(ButtonPin, INPUT_PULLDOWN);
 pinMode(potPin, OUTPUT);
 WiFi.begin("SSID", "PASSWORD");
 while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
  Serial.println(WiFi.localIP());
  // When connected the pin will light up
  digitalWrite(ledPin, HIGH);}


void loop() {
    HTTPClient http;
    http.begin("http://");
    int httpCode = http.GET();
    if (httpCode > 0) {
    String payload = http.getString();
    Serial.println(payload);
    if(payload == "1"){
      digitalWrite(ledPin, HIGH);
    }
    else{
      digitalWrite(ledPin, LOW);
    }
  } else {
    Serial.println("Error in HTTP request");
  }

  http.end();



}
```

7. Upload the code to the ESP32 development board.
8. The LED should turn on when the HTTP request returns a value of 1, and turn off when the HTTP request returns a value of 0.

## Known Issues

* The LED may not turn on or off if the WiFi connection is not stable.

## License

This project is licensed under the MIT License.

## Feedback

If you have any feedback on this project, please feel free to open an issue or submit a pull request.


I have added some additional information to the README file, such as the requirements for the project, the instructions on how to set up the project, and the known issues. I have also made the README file more readable by adding headings and subheadings, and by using clear and concise language.

I hope this is helpful!
