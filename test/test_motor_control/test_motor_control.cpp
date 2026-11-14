#include <Arduino.h>
#include "../../include/config.h"
#include "../../lib/MotorControl/MotorControl.h"

MotorControl motors;

void setup() {
    Serial.begin(115200);
    motors.init();
    Serial.println("Motor Test: Init complete");
}

void loop() {
    Serial.println("Motors ON (Forward)...");
    digitalWrite(IN1_PIN, HIGH);
    digitalWrite(IN2_PIN, LOW);
    digitalWrite(IN3_PIN, HIGH);
    digitalWrite(IN4_PIN, LOW);
    analogWrite(ENA_PIN, 150);
    analogWrite(ENB_PIN, 150);
    delay(2000);

    Serial.println("Stopping motors...");
    motors.stopMotors();
    delay(2000);
}