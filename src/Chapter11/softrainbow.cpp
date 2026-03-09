#include<Arduino.h>
#include<Freenove_WS2812_Lib_for_ESP32.h>

#define PIN_POT 1
#define PIN_LED 14
#define LED_COUNT 8
#define CHN 0
#define BLIGHTNESS 20

Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(LED_COUNT, PIN_LED, CHN, TYPE_BRG);

void setup() {
    strip.setBrightness(BLIGHTNESS);
    strip.begin();
}

void loop() {
    int colorPos = map(analogRead(PIN_POT), 0, 4095, 0, 255);
    for (int i = 0; i < LED_COUNT; i++)
    {
        strip.setLedColorData(i, strip.Wheel(colorPos + i * 255 / 8));
    }
    strip.show();
    delay(10);
}