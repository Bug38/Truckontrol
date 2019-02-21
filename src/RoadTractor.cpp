#include "RoadTractor.h"

/*
 * Constructor
 */
RoadTractor::RoadTractor() {};

/*
 * Init
 */
void RoadTractor::initPins(uint8_t motor, uint8_t servo, uint8_t lights, uint8_t reverseLights) {
  CTRL_MOTOR.attach(motor, 1000, 2000);
  CTRL_SERVO.attach(servo, 1000, 2000);

  pin_lights = lights;
  pinMode(pin_lights, OUTPUT);
  pin_reverseLights = reverseLights;
  pinMode(pin_reverseLights, OUTPUT);
}

/*
 * Movement
 */
void RoadTractor::move(uint16_t speedValue, uint16_t turnValue) {
  setSpeed(speedValue);
  setTurn(turnValue);
}

void RoadTractor::setSpeed(uint16_t speedValue) {
  if(speedValue == current_speed) return;
  current_speed = speedValue;
  if(speedValue < 1500) reverseLights(true);
  if(speedValue > 1500) reverseLights(false);
  CTRL_MOTOR.writeMicroseconds(speedValue);
}

void RoadTractor::setTurn(uint16_t turnValue) {
  if(turnValue == current_turn) return;
  CTRL_SERVO.writeMicroseconds(turnValue);
}

/*
 * Lights
 */
void RoadTractor::lights(bool lightsONOFF) {
  digitalWrite(pin_lights, lightsONOFF);
}


void RoadTractor::reverseLights(bool turnONOFF) {
  digitalWrite(pin_reverseLights, turnONOFF);
}