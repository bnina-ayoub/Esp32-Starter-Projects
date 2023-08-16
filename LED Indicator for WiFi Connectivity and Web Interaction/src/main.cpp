#include "esp_log.h"
#include "Arduino.h"
#include "WiFi.h"
#include "HTTPClient.h"

const int ledPin = 27;  //  Pin of LED  //  Pin of Relay
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