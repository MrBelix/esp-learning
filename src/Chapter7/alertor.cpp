#include <Arduino.h>

#define PIN_BUZ 14
#define PIN_BUTTON 21
#define CHN 0

void alert() {
    float sinVal;
    int toneVal;
    for (int x = 0; x < 360; x += 10)
    {
        sinVal = sin(x * (PI / 180));
        toneVal = 2000 + sinVal * 500;
        ledcWriteTone(CHN, toneVal);
        delay(10);
    }
    
}

void setup() {
    pinMode(PIN_BUTTON, INPUT);
    pinMode(PIN_BUZ, OUTPUT);
    ledcSetup(CHN, 1, 10);
    ledcAttachPin(PIN_BUZ, CHN);
    ledcWriteTone(CHN, 2000);
    delay(300);
}

void loop() {
    if (digitalRead(PIN_BUTTON) == LOW) {
        alert();
    } else {
        ledcWriteTone(CHN, 0);
    }
}