#ifndef CONFIG_H
#define CONFIG_H

// --- Safety Thresholds (from report) ---
#define LIDAR_THRESHOLD_MM 450
#define ULTRASONIC_THRESHOLD_CM 25

// --- Ultrasonic Sensor (HC-SR04) Pins ---
#define TRIG_PIN A0
#define ECHO_PIN A1

// --- Motor Driver (L298N) Pins ---
#define ENA_PIN 5
#define ENB_PIN 10
#define IN1_PIN 6
#define IN2_PIN 7
#define IN3_PIN 8
#define IN4_PIN 9

#endif