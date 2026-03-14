#include<Arduino.h>

#define PIN_IN 1
#define PIN_LED 14
#define CHN 0
#define LIGHT_MIN 372
#define LIGHT_MAX 2048

void setup() {
    ledcSetup(CHN, 1000, 12);
    ledcAttachPin(PIN_LED, CHN);
    Serial.begin(115200);
}

void loop() {
    int adcVal = analogRead(PIN_IN);
    int pwmVal = map(constrain(adcVal, LIGHT_MIN, LIGHT_MAX), LIGHT_MIN, LIGHT_MAX, 0, 4095);  // adcVal re-map to pwmVal
    Serial.printf("val: %d %d \r\n", adcVal, pwmVal);

    ledcWrite(CHN, pwmVal);
    delay(10);
}