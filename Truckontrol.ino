#include <Wire.h>
#include <Servo.h>
#include "settings.h"
#include "src/RoadTractor.h"
#include "src/FlySkyIBus/FlySkyIBus.h"

// Communication
//FlySkyIBus IBus; // Already declared in library

// Tractor
RoadTractor tractor;
Servo CTRL_SERVO;
Servo CTRL_MOTOR;

void setup () {
#define DEBUGSERIAL
#ifdef DEBUGSERIAL
  // Serial communication init
  Serial.begin(230400);
  while(!Serial);
  Serial.println("--------------------");
  Serial.println("  Truckontrol v0.1  ");
  Serial.println(__DATE__ " " __TIME__);
  Serial.println("--------------------");
#endif

  CTRL_SERVO.attach(9);  // attaches the servo on pin 9 to the servo object

  // // Communication
  IBus.begin(Serial2);
  Wire.begin(i2cMasterAddress);

  // // Tractor
  // tractor.initPins(p_motor, p_servo, p_lights);
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
  if(IBus.readChannel(7) == 2000)
    digitalWrite(LED_BUILTIN, HIGH);
  else
    digitalWrite(LED_BUILTIN, LOW);
  CTRL_SERVO.writeMicroseconds(IBus.readChannel(CHANNEL_SERVO));

  // // Drive Tractor
  // tractor.setSpeed(IBus.readChannel(ch_motor));
  // tractor.turn(IBus.readChannel(ch_servo));
  // tractor.setLight(IBus.readChannel(ch_lights));
}