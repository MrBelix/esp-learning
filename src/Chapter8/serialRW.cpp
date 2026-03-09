#include <Arduino.h>

String input = "";
bool inputCompleted = false;

void setup() {
    Serial.begin(115200);
    Serial.println("\nESP32S3 initialization completed!");
    Serial.println("Please input some characters,");
    Serial.println("select \"Newline\" below and Ctrl + Enter to send message to ESP32S3.");
    Serial.println("Ready to receive data...\n");
}

void loop() {
    if (Serial.available()) {
        input += Serial.readStringUntil('\n');
        input.trim();

        if (input.length() > 0) {
            inputCompleted = true;
        }
    }

    if (inputCompleted) {
        Serial.printf("input: %s\r\n", input.c_str());
        input = "";
        inputCompleted = false;
    }
}