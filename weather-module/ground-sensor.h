#ifndef GROUND_SENSOR_H
#define GROUND_SENSOR_H

#include <arduino.h>

#define GROUND_SERSOR_PIN 3

class GroundSensor {
  private:
    int _port = GROUND_SERSOR_PIN;
    float mapValue(float rawValue);

  public:
    int getValue();
};

#endif GROUND_SENSOR_H