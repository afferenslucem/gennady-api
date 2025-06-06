#include "ground-sensor.h"

int GroundSensor::getValue() {
  float rawValue = analogRead(this->_port);

  float result = this->mapValue(rawValue);

  return result;
}

float GroundSensor::mapValue(float rawValue) {
  float result = (1023 - rawValue) / 1023 * 100.0;

  return result;
}