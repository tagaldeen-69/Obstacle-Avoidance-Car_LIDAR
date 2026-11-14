\# System Architecture



The robot consists of the following main modules:

\* Arduino Uno (Main Controller)

\* RPLIDAR A1

\* HC-SR04 Ultrasonic Sensor

\* L298N Motor Driver

\* Two DC Geared Motors

\* Rechargeable Battery



\## Integration Flow



```text

&#x20;         +-----------------------+

&#x20;         |  Rechargeable Battery |

&#x20;         +-----------------------+

&#x20;                   | (Raw Power to Vin / Vms)

&#x20;                   v

+-------------------+       +---------------+

|    ARDUINO UNO    |------>|  L298N Motor  |

| (Main Controller) | (PWM) |    Driver     |

+-------------------+       +---------------+

&#x20;         |                         | (Drive Power)

&#x20;         | (5V Regulated           v

&#x20;         |  Power Output)  +---------------+

&#x20;         +----+            | 2x DC Geared  |

&#x20;         v    v            |    Motors     |

+-----------+ +-----------+ +---------------+

| RPLIDAR A1| |  HC-SR04  |

|  (LiDAR)  | | Ultrasonic|

+-----------+ +-----------+

