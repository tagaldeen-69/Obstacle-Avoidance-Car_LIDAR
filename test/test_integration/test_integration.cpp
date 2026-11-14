#include <Arduino.h>
#include "../../include/config.h"
#include "../../lib/ObstacleFusionLogic/ObstacleFusionLogic.h"

ObstacleFusionLogic fusion;

void setup() {
    Serial.begin(115200);
    Serial.println("Fusion Logic Test Started");
}

void loop() {
    // Simulated Safe Distances
    bool danger = fusion.isObstacleDetected(600.0, 40.0);
    Serial.print("Test 1 (Safe) - Expected 0, Got: ");
    Serial.println(danger);

    // Simulated LiDAR Danger (under 450mm)
    danger = fusion.isObstacleDetected(400.0, 40.0);
    Serial.print("Test 2 (LiDAR Danger) - Expected 1, Got: ");
    Serial.println(danger);

    // Simulated Ultrasonic Danger (under 25cm)
    danger = fusion.isObstacleDetected(600.0, 15.0);
    Serial.print("Test 3 (Ultra Danger) - Expected 1, Got: ");
    Serial.println(danger);

    delay(3000);
}