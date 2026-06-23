//#include <Arduino.h>//
/*int a = 10;
void setup() {
Serial.begin(115200);
}
 void loop() {
  Serial.print("current value of a = ");
  Serial.println(a);
  a++;
  delay(500);
 }*/
 /* #include <Arduino.h>

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
}*/

  #include <Arduino.h>

#define LED_PIN 2       // GPIO pin for LED
#define PWM_CHANNEL 0   // PWM channel
#define PWM_FREQ 5000   // PWM frequency in Hz
#define PWM_RES 8       // 8-bit resolution (0-255)

String input = "";

void setup() {
    Serial.begin(115200);

    // Setup PWM for ESP32
    ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RES);
    ledcAttachPin(LED_PIN, PWM_CHANNEL);

    Serial.println("Enter brightness value (0-255):");
}

void loop() {
    if (Serial.available()) {
        input = Serial.readStringUntil('\n');
        input.trim();

        int brightness = input.toInt();

        if (brightness >= 0 && brightness <= 255) {
            ledcWrite(PWM_CHANNEL, brightness);
            Serial.print("LED brightness set to: ");
            Serial.println(brightness);
        } else {
            Serial.println("Invalid input! Enter a number between 0 and 255.");
        }
    }
}

