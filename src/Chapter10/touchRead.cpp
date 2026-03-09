#include<Arduino.h>

void setup() {
    Serial.begin(115200);
}

void loop() {
    Serial.printf("Touch value: %d \r\n", touchRead(T14));
    delay(1000);
}