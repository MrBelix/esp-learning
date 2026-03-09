#include<Arduino.h>

const byte ledPins[] = {38, 39, 40};
const byte adcChns[] = {12, 13, 14};

int colors[] = {0,0,0};

void setup() {
    Serial.begin(115200);
    for(int i = 0; i < 3; i++) {
        ledcSetup(i, 1000, 8);
        ledcAttachPin(ledPins[i], i);
    }
}

void loop() {
    for (int i = 0; i < 3; i++) {
        colors[i] = map(analogRead(adcChns[i]), 0, 4096, 0, 255);
        Serial.printf("%d,%d,%d\r\n", colors[0],colors[1], colors[2]);
        ledcWrite(i, 256 - colors[i]);
    }
    delay(10);
}