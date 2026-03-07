#include <Arduino.h>
#include <Freenove_WS2812_Lib_for_ESP32.h>

#define LEDS_COUNT 8
#define LEDS_PIN 48
#define CHANNEL 0
#define LED_DELAY 100
#define GROUP_DELAY 500

struct RgbColor
{
    uint8_t r; // Red channel (0-255)
    uint8_t g; // Green channel (0-255)
    uint8_t b; // Blue channel (0-255)

    RgbColor(uint8_t r, uint8_t g, uint8_t b)
    {
        this->r = r;
        this->g = g;
        this->b = b;
    }
};

Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN, TYPE_GRB);

RgbColor m_color[5] = {
    RgbColor(255, 0, 0),
    RgbColor(0, 255, 0),
    RgbColor(0, 0, 255),
    RgbColor(255, 255, 255),
    RgbColor(0, 0, 0)
};

void setup() {
    strip.begin();
    strip.setBrightness(10);
}

void loop() {
    int colorSize = sizeof(m_color);

    for (int i = 0; i < colorSize; i++)
    {
        for (int led = 0; led < LEDS_COUNT; led++)
        {
            RgbColor color = m_color[i];
            strip.setLedColorData(led, color.r, color.g, color.b);
            strip.show();
            delay(LED_DELAY);
        }

        delay(GROUP_DELAY);
    }
    
}