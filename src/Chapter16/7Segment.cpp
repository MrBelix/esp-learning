#include<Arduino.h>

#define PIN_DATA 12
#define PIN_LATCH 13
#define PIN_CLOCK 14

byte num[] = {
    0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8,
    0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e
};

void writeData(int value)
{
    digitalWrite(PIN_LATCH, LOW);
    shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, value);
    digitalWrite(PIN_LATCH, HIGH);
}

void setup() {
    pinMode(PIN_LATCH, OUTPUT);
    pinMode(PIN_CLOCK, OUTPUT);
    pinMode(PIN_DATA, OUTPUT);
}

void loop() {
    for (int i = 0; i < 16; i++)
    {
        writeData(num[i]);
        delay(1000);
        writeData(0xff);
    }
    
}