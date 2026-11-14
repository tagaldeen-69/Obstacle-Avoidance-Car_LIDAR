\# Configuration Headers (`include/`)



This directory contains the central configuration file (`config.h`) for the Obstacle Avoidance Robot. 



\## System Parameters

Based on the sensor fusion architecture, the robot relies on two distinct thresholds to safely stop and navigate around obstacles:

\* \*\*LiDAR (RPLIDAR A1):\*\* Triggers avoidance maneuvers when an obstacle is detected within \*\*450 mm\*\*.

\* \*\*Ultrasonic (HC-SR04):\*\* Acts as a close-range backup, triggering at \*\*25 cm\*\* for objects the LiDAR might miss.



\## Hardware Mapping

\* `config.h` statically defines the Arduino Uno pins connected to the L298N motor driver (PWM for speed control, Digital for direction) and the HC-SR04 sensor. 

\* \*Note: The RPLIDAR A1 TX/RX pins are handled via SoftwareSerial in the main source code, not statically defined here.\*

