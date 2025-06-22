#include<ESP8266WiFi.h>
// Pin connected to the LED
const int ledPin = 2;

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Turn on the LED
  digitalWrite(ledPin, HIGH);
  delay(1000); // Wait for 1 second
  
  // Turn off the LED
  digitalWrite(ledPin, LOW);
  delay(1000); // Wait for 1 second
}
