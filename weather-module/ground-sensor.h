#ifndef GROUND_SENSOR_H
#define GROUND_SENSOR_H

#include <arduino.h>

class GroundSensor {
  private:
    int _port;
    float mapValue(float rawValue);

  public:
    GroundSensor(int port);
    int getValue();
};

#endif GROUND_SENSOR_H