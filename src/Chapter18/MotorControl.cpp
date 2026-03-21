#include<Arduino.h>

#define PIN_RELAY 14
#define PIN_BUTTON 21

int buttonState = HIGH;
int relayState = LOW;
int lastButtonState = HIGH;
long lastChangeTime = 0;

void setup() {
    pinMode(PIN_BUTTON, INPUT_PULLUP);
    pinMode(PIN_RELAY, OUTPUT);
    digitalWrite(PIN_RELAY, relayState);
    Serial.begin(115200);
}

void loop() {
    int nowButtonState = digitalRead(PIN_BUTTON);
    if (nowButtonState != lastButtonState) {
        lastChangeTime = millis();
    }

    if (millis() - lastChangeTime > 10) {
        if (buttonState != nowButtonState) {
            buttonState = nowButtonState;
            if (buttonState != LOW) {
                relayState = !relayState;
                digitalWrite(PIN_RELAY, relayState);
            }
        }
    }

    lastButtonState = nowButtonState;
}