#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <Arduino.h>
#include "../../include/config.h"

class MotorControl {
public:
    void init() {
        pinMode(ENA_PIN, OUTPUT);
        pinMode(ENB_PIN, OUTPUT);
        pinMode(IN1_PIN, OUTPUT);
        pinMode(IN2_PIN, OUTPUT);
        pinMode(IN3_PIN, OUTPUT);
        pinMode(IN4_PIN, OUTPUT);
    }

    void stopMotors() {
        digitalWrite(IN1_PIN, LOW);
        digitalWrite(IN2_PIN, LOW);
        digitalWrite(IN3_PIN, LOW);
        digitalWrite(IN4_PIN, LOW);
        analogWrite(ENA_PIN, 0);
        analogWrite(ENB_PIN, 0);
    }
};

#endif