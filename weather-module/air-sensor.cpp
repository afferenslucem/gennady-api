#include "air-sensor.h"

AirMeassure::AirMeassure(int temperature, int humidity) {
  this->humidity = humidity;
  this->temperature = temperature;
}

AirMeassure AirSensor::meassure() {
  int temperature = 0;
  int humidity = 0;

  int result = this->dht11.readTemperatureHumidity(temperature, humidity);

  if (result == 0) {
    return AirMeassure(temperature, humidity);
  } else {
    Serial.println(DHT11::getErrorString(result));
    return AirMeassure(-1, -1);
  }
}