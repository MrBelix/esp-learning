#include<Arduino.h>

#define PIN 1

void setup() {
    Serial.begin(115200);
}

void loop() {
    int adcValue = analogRead(PIN);
    double voltage = adcValue / 4095.0f * 3.3;
    Serial.printf("ADC Val: %d, \t Voltage: %.2fV\r\n", adcValue, voltage);
    delay(200);
}