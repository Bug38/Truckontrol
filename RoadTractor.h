#ifndef __RoadTractor_h__
#define __RoadTractor_h__

#include <Arduino.h>

class RoadTractor {
  public:
    // Build class instance
    RoadTractor();
    // Setup pins
    void initPins(uint8_t motor, uint8_t servo);
    void initPins(uint8_t motor, uint8_t servo, uint8_t front_lights);
    void initPins(uint8_t motor, uint8_t servo, uint8_t front_lights, uint8_t rear_lights);
    // Movements
    void move(uint8_t speed, uint8_t direction);
    void setSpeed(uint8_t speed);
    void turn(uint8_t direction);
    // Misc
    void setLight(uint8_t lights);
    
  private:
    uint8_t pin_front_lights;
    uint8_t pin_rear_lights;
    uint8_t pin_motor;
    uint8_t pin_servo;

    int8_t current_speed;
    int8_t current_direction;
};

#endif //__RoadTractor_h__