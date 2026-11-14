#include <Arduino.h>
#include <SoftwareSerial.h>
#include "../include/config.h"
#include "../lib/MotorControl/MotorControl.h"
#include "../lib/ObstacleFusionLogic/ObstacleFusionLogic.h"
#include "../lib/RPLidarInterface/RPLidarInterface.h"
#include "../lib/UltrasonicSensor/UltrasonicSensor.h"

// Define SoftwareSerial pins for RPLidar (Arduino RX=2, TX=3)
SoftwareSerial lidarSerial(2, 3);

// Initialize library objects
MotorControl motors;
ObstacleFusionLogic fusionLogic;
RPLidarInterface lidarSensor;
UltrasonicSensor ultrasonicSensor;

void setup() {
    Serial.begin(115200);
    
    motors.init();
    ultrasonicSensor.init();
    lidarSensor.init(&lidarSerial);
    
    Serial.println("System Ready: Sensor Fusion Active");
}

void loop() {
    // 1. Gather sensor data
    float lidarDist = lidarSensor.getDistance();
    float ultraDist = ultrasonicSensor.getDistanceCM();
    
    // 2. Pass data to fusion logic for safety check
    bool obstacleAhead = fusionLogic.isObstacleDetected(lidarDist, ultraDist);
    
    // 3. Execute movement commands
    if (obstacleAhead) {
        motors.stopMotors();
        Serial.println("Danger: Obstacle within threshold! Motors stopped.");
    } else {
        // Safe to move forward
        digitalWrite(IN1_PIN, HIGH);
        digitalWrite(IN2_PIN, LOW);
        digitalWrite(IN3_PIN, HIGH);
        digitalWrite(IN4_PIN, LOW);
        analogWrite(ENA_PIN, 150); // Set speed
        analogWrite(ENB_PIN, 150);
    }
}