#include <Arduino.h>
#include "../../include/config.h"
#include "../../lib/UltrasonicSensor/UltrasonicSensor.h"

UltrasonicSensor ultrasonic;

void setup() {
    Serial.begin(115200);
    ultrasonic.init();
    Serial.println("Ultrasonic Test Started");
}

void loop() {
    float dist = ultrasonic.getDistanceCM();
    Serial.print("Ultrasonic Distance (cm): ");
    Serial.println(dist);
    delay(500);
}