#include "RoadTractor.h"

RoadTractor::RoadTractor() {};

void RoadTractor::initPins(uint8_t motor, uint8_t servo) {
  initPins(motor, servo, 0, 0);
}
void RoadTractor::initPins(uint8_t motor, uint8_t servo, uint8_t front_lights) {
  initPins(motor, servo, front_lights, 0);
}
void RoadTractor::initPins(uint8_t motor, uint8_t servo, uint8_t front_lights, uint8_t rear_lights) {
  pin_front_lights = front_lights;
  pin_rear_lights  = rear_lights;
  pin_motor        = motor;
  pin_servo        = servo;
  
  // Outputs
  pinMode(pin_front_lights, OUTPUT);
  pinMode(pin_rear_lights, OUTPUT);
  pinMode(pin_motor, OUTPUT);
  pinMode(pin_servo, OUTPUT);
}

void RoadTractor::move(uint8_t speed, uint8_t direction) {
  setSpeed(speed);
  turn(direction);
}

void RoadTractor::setSpeed(uint8_t speed) {
  if(speed == current_speed)
    return;
  analogWrite(pin_motor,map(speed, 1000, 2000, 12, 25));
}

void RoadTractor::turn(uint8_t direction) {
  if(direction == current_direction)
    return;
  analogWrite(pin_motor,map(direction, 1000, 2000, 12, 25));
}

void RoadTractor::setLight(uint8_t lights) {

}