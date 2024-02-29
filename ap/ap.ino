#include <ESP8266WiFi.h>

const char* ssid = "YASSINE 6827"; // Set your router's SSID
const char* password = "00000000"; // Set your router's password

void setup() {
    Serial.begin(9600);
    WiFi.mode(WIFI_AP_STA); // Set both STA and AP mode
    WiFi.begin(ssid, password); // Connect to your router
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print("."); //this is a test adding something new
        
    }
    Serial.println("\nConnected to Wi-Fi");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    // Set up your AP here
    // Example: WiFi.softAP("MyESP8266AP", "APPassword");
}

void loop() {
    // Your additional code here
}
