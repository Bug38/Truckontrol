#include <Wire.h>
#include <Servo.h>
#include "settings.h"
#include "src/RoadTractor.h"
#include "src/FlySkyIBus/FlySkyIBus.h"

// Communication
//FlySkyIBus IBus; // Already declared in library

// Tractor
RoadTractor tractor;

uint16_t getSpeedCommand(uint16_t s, uint16_t g) {
  switch (g) {
    case MIN_CHANNEL_VALUE:
      return MED_CHANNEL_VALUE - (s - MIN_CHANNEL_VALUE) / 4;
      break;
    case MED_CHANNEL_VALUE:
      return MED_CHANNEL_VALUE + (s - MIN_CHANNEL_VALUE) / 4;
      break;
    case MAX_CHANNEL_VALUE:
      return MED_CHANNEL_VALUE + (s - MIN_CHANNEL_VALUE) / 2;
      break;
    default:
      break;
  }
}

void setup () {
// Serial debug
#define DEBUGSERIAL
#ifdef DEBUGSERIAL
  Serial.begin(230400);
  while(!Serial);
  Serial.println("--------------------");
  Serial.println("  Truckontrol v0.1  ");
  Serial.println(__DATE__ " " __TIME__);
  Serial.println("--------------------");
#endif

  // Init Communication
  IBus.begin(Serial2);
  Wire.begin(i2cMasterAddress);

  // Define Tractor
  tractor.initPins(p_motor, p_servo, p_lights, p_reverseLights);
}

int i = 0;

void loop() {
  // // Receive Commands
  IBus.loop();
#ifdef DEBUGSERIAL
  Serial.print(millis());
  Serial.print(" - ");
  for(uint8_t c = 0; c < 10; c++)
  { Serial.print(IBus.readChannel(c)); Serial.print(", "); }
  Serial.println();
#endif
  tractor.lights(IBus.readChannel(ch_lights) == MAX_CHANNEL_VALUE);
  tractor.move(getSpeedCommand(IBus.readChannel(ch_motor), IBus.readChannel(ch_gearbox)), IBus.readChannel(ch_servo));
}
