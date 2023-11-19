#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include "asbQuadcopter.h"

Adafruit_MPU6050 mpu;

void setup(void) {
  Serial.begin(115200);
  asbQuadcopter_initialize();
}

void loop() {
  asbQuadcopter_step();
  delay(10);
}