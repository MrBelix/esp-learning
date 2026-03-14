#include<Arduino.h>

#define PIN_LATCH 13
#define PIN_CLOCK 14
#define PIN_DATA 12

void writeTo595(int order, byte _data)
{
    digitalWrite(PIN_LATCH, LOW);
    shiftOut(PIN_DATA, PIN_CLOCK, order, _data);
    digitalWrite(PIN_LATCH, HIGH);
}

void setup() {
    pinMode(PIN_LATCH, OUTPUT);
    pinMode(PIN_CLOCK, OUTPUT);
    pinMode(PIN_DATA, OUTPUT);
}

void loop() {
    byte x = 0x01;
    for (int i = 0; i < 8; i++)
    {
        writeTo595(LSBFIRST, x);
        x <<= 1;
        delay(50);
    }
    delay(100);
    x = 0x80;

    for (int i = 0; i < 8; i++)
    {
        writeTo595(LSBFIRST, x);
        x >>= 1;
        delay(50);
    }
    delay(100);
}