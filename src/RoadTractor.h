#ifndef __RoadTractor_h__
#define __RoadTractor_h__

#include <Arduino.h>
#include <Servo.h>

class RoadTractor {
  public:
    // Build class instance
    RoadTractor();
    // Setup pins
    void initPins(uint8_t motor, uint8_t servo, uint8_t lights, uint8_t reverseLights);
    // Movements
    void move(uint16_t speedValue, uint16_t turnValue);
    // Lights
    void lights(bool turnONOFF);
    
  private:
    void setSpeed(uint16_t speedValue);
    void setTurn(uint16_t turnValue);
    void reverseLights(bool lightsONOFF);

    Servo   CTRL_SERVO;
    Servo   CTRL_MOTOR;
    uint8_t pin_lights;
    uint8_t pin_reverseLights;

    int16_t current_speed;
    int16_t current_turn;
};

#endif //__RoadTractor_h__