#ifndef OBSTACLE_FUSION_LOGIC_H
#define OBSTACLE_FUSION_LOGIC_H

#include "../../include/config.h"

class ObstacleFusionLogic {
public:
    bool isObstacleDetected(float lidarDistanceMM, float ultrasonicDistanceCM) {
        bool lidarDanger = (lidarDistanceMM > 0 && lidarDistanceMM <= LIDAR_THRESHOLD_MM);
        bool ultrasonicDanger = (ultrasonicDistanceCM > 0 && ultrasonicDistanceCM <= ULTRASONIC_THRESHOLD_CM);
        
        return (lidarDanger || ultrasonicDanger);
    }
};

#endif