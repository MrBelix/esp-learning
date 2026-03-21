#include<Arduino.h>
#include<LiquidCrystal_I2C.h>
#include<Wire.h>

#define SDA 14
#define SCL 13

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    Wire.begin(SDA, SCL);
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("hello, world!");
}

void loop() {
    lcd.setCursor(0, 1);
    lcd.print("Counter:");
    lcd.print(millis() / 1000);
    delay(1000);
}

bool i2CAddrTest(uint8_t addr) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
        return true;
    }
    
    return false;
}