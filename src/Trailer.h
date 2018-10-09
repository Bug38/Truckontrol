#ifndef __Trailer_h__
#define __Trailer_h__

#include <Arduino.h>

class Trailer {
  public:
    // Build class instance
    Trailer(uint8_t address) : address(address);
    // Actions
    virtual void park(); // May need some pins -> which mecanical method to use to setup trailer park actuators ?
    
  private:
    uint8_t address;
};

#endif //__Trailer_h__