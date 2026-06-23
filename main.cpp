#include <Arduino.h>

#define LED_PIN 2   // GPIO 2

String input = "";

void setup() {
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);   // start OFF

    Serial.println("Type ON to turn GPIO2 ON");
    Serial.println("Type OFF to turn GPIO2 OFF");
}

void loop() {
    if (Serial.available()) {
        input = Serial.readStringUntil('\n');  // read line from serial
        input.trim();                          // remove spaces/newline
        input.toUpperCase();                   // make input case-insensitive

        if (input == "ON") {
            digitalWrite(LED_PIN, HIGH);
            Serial.println("GPIO 2 is ON");
        }
        else if (input == "OFF") {
            digitalWrite(LED_PIN, LOW);
            Serial.println("GPIO 2 is OFF");
        }
        else {
            Serial.println("Invalid command. Type ON or OFF");
        }
    }
}

