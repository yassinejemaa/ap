#include <Arduino.h>
#include <painlessMesh.h>
#define LED_PIN 14

painlessMesh mesh;

void receivedCallback(uint32_t from, String &msg) {
  Serial.printf("Received from %u: %s\n", from, msg.c_str());

  // Check the content of the message
  if (msg == "toggleLED") {
    digitalWrite(LED_PIN, HIGH); // Turn on the LED
    delay(1000); // Wait for 1 second
    digitalWrite(LED_PIN, LOW); // Turn off the LED
  }
}

void setup() {
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);

  mesh.setDebugMsgTypes(ERROR | STARTUP | CONNECTION);
  mesh.init("testing", "00000000", 5555);
  mesh.onReceive(receivedCallback);
}

void loop() {
  mesh.update();
  
}
