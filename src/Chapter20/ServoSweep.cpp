#include<Arduino.h>

#define PIN_SERVO 21
#define SERVO_CHN 0
#define SERVO_FRQ 50
#define SERVO_BIT 12

void servoSetAngle(int angle) {
    if (angle < 0 || angle > 180)
        return;

    long pwm_value = map(angle, 0, 180, 103, 512);
    ledcWrite(SERVO_CHN, pwm_value);
}

void setup() {
    ledcSetup(SERVO_CHN, SERVO_FRQ, SERVO_BIT);
    ledcAttachPin(PIN_SERVO, SERVO_CHN);
}

void loop() {
    for (int i = 0; i < 180; i++) {
        servoSetAngle(i);
        delay(10);
    }
    for (int i = 180; i > 0; i--) {
        servoSetAngle(i);
        delay(10);
    }
}