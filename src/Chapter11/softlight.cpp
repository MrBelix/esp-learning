#include<Arduino.h>

#define PIN_IN 1
#define PIN_LED 14
#define CHN 0

void setup() {
    ledcSetup(CHN, 1000, 12);
    ledcAttachPin(PIN_LED, CHN);
}

void loop() {
    int adcVal = analogRead(PIN_IN);
    ledcWrite(CHN, adcVal);
    delay(10);
}