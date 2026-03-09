#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    Serial.println("Esp32s3 initializaion completed!");
}

void loop() {
    Serial.printf("Running time: %.1f s\r\n", millis() / 1000.0f);
    delay(1000);
}