#ifndef RP_LIDAR_INTERFACE_H
#define RP_LIDAR_INTERFACE_H

#include <RPLidar.h>
#include <SoftwareSerial.h>

class RPLidarInterface {
private:
    RPLidar lidar;
    SoftwareSerial* lidarSerial;

public:
    void init(SoftwareSerial* serialPort) {
        lidarSerial = serialPort;
        lidarSerial->begin(115200);
        lidar.begin(*lidarSerial);
    }

    float getDistance() {
        if (IS_OK(lidar.waitPoint())) {
            return lidar.getCurrentPoint().distance; // Returns mm
        }
        return -1.0; 
    }
};

#endif