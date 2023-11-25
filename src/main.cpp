#include "asbQuadcopter.h"


void setup(void) {
  Serial.begin(115200);
  asbQuadcopter_initialize();
}

void loop() {
  asbQuadcopter_step();
  Serial.print(motors_outport[0]);
  Serial.print("  ");
  Serial.print(motors_outport[1]);
  Serial.print("  ");
  Serial.print(motors_outport[2]);
  Serial.print("  ");
  Serial.println(motors_outport[3]);
  delay(10);
}