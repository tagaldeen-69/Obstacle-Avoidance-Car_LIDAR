#include <Arduino.h>
#include <SoftwareSerial.h>
#include "../../include/config.h"
#include "../../lib/RPLidarInterface/RPLidarInterface.h"

SoftwareSerial lidarSerial(2, 3);
RPLidarInterface lidar;

void setup() {
    Serial.begin(115200);
    lidar.init(&lidarSerial);
    Serial.println("LiDAR Test Started");
}

void loop() {
    float dist = lidar.getDistance();
    if (dist > 0) {
        Serial.print("LiDAR Distance (mm): ");
        Serial.println(dist);
    }
    delay(100);
}