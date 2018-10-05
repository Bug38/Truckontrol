#include <Wire.h>
#include "settings.h"
#include "RoadTractor.h"

// Tractor
RoadTractor tractor;

void setup () {
  // Communication
  Wire.begin(i2cMasterAddress);

  // Tractor
  tractor.initPins(pin_motor, pin_servo, pin_lights);
}

void loop() {
  // tbd
}