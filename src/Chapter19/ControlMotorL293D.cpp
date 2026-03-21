#include<Arduino.h>

#define PIN_IN1 13
#define PIN_IN2 14
#define PIN_ENABLE1 12
#define CHN 0

bool rotationDir;
int speed;

void driveMotor(boolean dir, int spd) {
  // Control motor rotation direction
  if (dir) {
    digitalWrite(PIN_IN1, HIGH);
    digitalWrite(PIN_IN2, LOW);
  }
  else {
    digitalWrite(PIN_IN1, LOW);
    digitalWrite(PIN_IN2, HIGH);
  }
  // Control motor rotation speed
  ledcWrite(CHN, spd);
}
void setup() {
    pinMode(PIN_IN1, OUTPUT);
    pinMode(PIN_IN2, OUTPUT);
    pinMode(PIN_ENABLE1, OUTPUT);
    ledcSetup(CHN, 1000, 11);
    ledcAttachPin(PIN_ENABLE1, CHN);

    Serial.begin(115200);
}

void loop() {
    int potVal = analogRead(A0);

    speed = potVal - 2048;

    rotationDir = speed > 0;
    speed = abs(speed);
    Serial.println(speed);
    delay(100);
    driveMotor(rotationDir, constrain(speed, 0, 2048));
}